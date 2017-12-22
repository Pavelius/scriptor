#include "cface/draw.h"
#include "cface/draw_control.h"
#include "cface/hotproc.h"
#include "main.h"

using namespace c2;
using namespace draw;

void opendilaog(symbol& e) {
	draw::window dc(-1, -1, 300, 100, WFMinmax, 32, "symbol");
	draw::setcaption("New symbol");
	while(true) {
		rect rc = {0, 0, draw::getwidth(), draw::getheight()};
		draw::rectf(rc, colors::form);
		auto id = draw::input();
		switch(id) {
		case KeyEscape:
		case 0:
			return;
		}
		if(!id)
			return;
		control::dodialog(id);
	}
}

static void create_module() {
	symbol e;
	opendilaog(e);
}

static hotproc hotkeys[] = {
	{Ctrl + Alpha + 'N', create_module},
	{0}
};
static hotproc::plugin plugin(hotkeys);