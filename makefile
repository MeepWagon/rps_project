ui_path = ui/main.blp
build_path = build
build_flags = `pkg-config --cflags --libs gtk4`

ui_files := $(shell find ui -type f)
src_files := $(shell find src -type f)

build: $(ui_files) $(src_files)
	rm -rf build
	mkdir build
	blueprint-compiler compile $(ui_path) > $(build_path)/main.ui
	gcc src/*.c -o $(build_path)/rps_game $(build_flags)

clean:
	rm -rf build

run: build 
	build/rps_game &