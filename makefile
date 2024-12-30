setup:
	mkdir build
	meson setup build

compile:
	cd build && meson compile

run:
	./build/PokeViewerGUI

