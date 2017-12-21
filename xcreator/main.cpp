#include "main.h"

using namespace c2;

int main(int argc, char *argv[]) {
	symbol::initialize();
	return 0;
}

int _stdcall WinMain(void* ci, void* pi, char* cmd, int sw) {
	return main(0, 0);
}