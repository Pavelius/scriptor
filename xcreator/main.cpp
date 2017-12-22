#include "cface/draw.h"
#include "cface/io.h"
#include "view.h"

using namespace c2;

int main(int argc, char *argv[]) {
	symbol::initialize();
	draw::initialize();
	io::read("settings.xml", "settings", 0);
	c2::view::loadproject("E:/documents/scripter/projects/test");
	expression e1(Add, new expression(10), new expression(12));
	draw::application("Test Application");
	io::write("settings.xml", "settings", 0);
	return 0;
}

int _stdcall WinMain(void* ci, void* pi, char* cmd, int sw) {
	return main(0, 0);
}