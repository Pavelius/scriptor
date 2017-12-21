#include "main.h"

using namespace c2;

int main(int argc, char *argv[]) {
	symbol::initialize();
	expression e1(Add, new expression(10), new expression(12));
	return 0;
}

int _stdcall WinMain(void* ci, void* pi, char* cmd, int sw) {
	return main(0, 0);
}