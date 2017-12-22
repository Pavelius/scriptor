#include "main.h"

using namespace c2;

enum flag_s : char {
	Public, Static, Readed, Writed, Pseudoname
};

static agrw<symbol> symbols;
static agrw<symbol> pointers;

static symbol* standart_types[] = {i8, i16, i32, u8, u16, u32, v0};
static unsigned	pointer_size = 4;
symbol c2::i8[1]; // Байт со знаком
symbol c2::i16[1]; // Слово со знаком
symbol c2::i32[1]; // Двойное слово со знаком
symbol c2::u8[1]; // Байт без знака
symbol c2::u16[1]; // Слово без знака
symbol c2::u32[1]; // Двойное слово без знака
symbol c2::v0[1]; // Путое значение

symbol::symbol() {
	memset(this, 0, sizeof(this));
}

void* symbol::operator new(unsigned size) {
	return symbols.add();
}

bool symbol::ispointer() const {
	return id[0] == '*';
}

symbol* symbol::reference() {
	if(!this)
		return 0;
	for(auto pel = &pointers; pel; pel = pel->next) {
		for(auto& e : *pel) {
			if(e.result == this && e.ispointer())
				return &e;
		}
	}
	auto p = new symbol;
	p->result = this;
	p->id = szdup("*");
	p->size = pointer_size;
	return p;
}

symbol* symbol::dereference() {
	if(!ispointer())
		return 0;
	return result;
}

void basetype(symbol* p, const char* name, unsigned size) {
	p->id = szdup(name);
	p->size = size;
}

void symbol::initialize() {
	basetype(i8, "int8", 1);
	basetype(i16, "int16", 2);
	basetype(i32, "int32", 4);
	basetype(u8, "uint8", 1);
	basetype(u16, "uint16", 2);
	basetype(u32, "uint32", 4);
	basetype(v0, "void", 0);
}