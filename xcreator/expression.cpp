#include "agrw.h"
#include "main.h"

using namespace c2;

static adat<expression, 4096>	expressions;

bool expression::isdeterminal() const {
	return type == Value || type == Symbol;
}