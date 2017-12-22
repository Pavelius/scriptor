#include "cface/crt.h"
#include "cface/adat.h"
#include "cface/agrw.h"

#pragma once

namespace c2 {
	namespace url {
		extern const char*	project;
		extern const char*	projects;
		extern const char*	library;
	}
	struct symbol {
		symbol*				result;
		const char*			id;
		unsigned			size;
		unsigned			count;
		unsigned			flags;
		symbol*				next;
		symbol*				child;
		symbol*				parent;
		//
		symbol();
		void* operator new(unsigned size);
		operator bool() const { return id != 0; }
		static symbol*		add();
		void				clear();
		symbol*				dereference();
		symbol*				getchild() const { return child; }
		symbol*				getnext() const { return next; }
		symbol*				getparent() const { return parent; }
		static void			initialize();
		bool				islocal() const;
		bool				ispointer() const;
		symbol*				reference();
	};
	extern symbol			i8[]; // Signed byte
	extern symbol			i16[]; // Signed word
	extern symbol			i32[]; // Signed double word
	extern symbol			u8[]; // Unsigned byte
	extern symbol			u16[]; // Unsigned word
	extern symbol			u32[]; // Unsigned double word
	extern symbol			v0[]; // Void value or NO value
	enum expression_s : unsigned char {
		NoExpression,
		Value, Symbol,
		Not, Neg,
		Or, Xor, And,
		Add, Sub, Mul, Div,
		Equal, NotEqual, Lesser, Greater, LesserEqual, GreaterEqual,
		If, Else, While, Expression,
	};
	struct expression {
		expression_s		type;
		union {
			struct {
				expression*	left;
				expression*	right;
			};
			struct {
				symbol*		result; // Can be type, pointer or member
				unsigned	value;
			};
		};
		expression() {}
		~expression();
		expression(expression_s type, expression* left, expression* right) : type(type), left(left), right(right) {}
		expression(symbol* identifier) : type(Symbol), result(identifier), value(0) {}
		expression(int value) : type(Value), result(i8), value(0) {}
		void* operator new(unsigned size);
		void operator delete(void* object, unsigned size);
		bool				isdeterminal() const { return type <= Symbol; }
		symbol*				getsymbol() const { return isdeterminal() ? result : 0; }
		unsigned			getvalue() const { return isdeterminal() ? value : 0; }
	};
}