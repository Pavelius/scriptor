#include "main.h"
#include "cface/agrw.h"

using namespace c2;

static agrw<expression, 4096>	expressions;

expression::~expression() {
	if(!isdeterminal()) {
		if(right)
			delete right;
		if(left)
			delete left;
		left = 0;
		right = 0;
	}
}

void* expression::operator new(unsigned size) {
	return expressions.add();
}

void expression::operator delete(void* object, unsigned size) {
	((expression*)object)->type = NoExpression;
}