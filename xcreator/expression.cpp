#include "agrw.h"
#include "main.h"

using namespace c2;

static agrw<expression, 4096>	expressions;

void* expression::operator new(unsigned size) {
	return expressions.add();
}