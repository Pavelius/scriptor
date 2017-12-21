#include "adat.h"

#pragma once

namespace c2 {
	enum expression_s : unsigned char {
		Value, Symbol,
		If, Else, While, Expression,
	};
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
	struct expression {
		expression_s		type;
		union {
			struct {
				expression*	left;
				expression*	right;
			};
			struct {
				unsigned	value;
				symbol*		result;
			};
		};
		bool				isdeterminal() const;
		expression() {}
		expression(expression_s type) : type(type), left(0), right(0) {}
	};
	extern symbol			i8[]; // Signed byte
	extern symbol			i16[]; // Signed word
	extern symbol			i32[]; // Signed double word
	extern symbol			u8[]; // Unsigned byte
	extern symbol			u16[]; // Unsigned word
	extern symbol			u32[]; // Unsigned double word
	extern symbol			v0[]; // Void value or NO value
}