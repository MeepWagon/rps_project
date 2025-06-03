application_name = rps_game

ui_path = ui/main.blp
build_path = build
application_path = $(build_path)/$(application_name)

build_flags = `pkg-config --cflags --libs gtk4`
debug_flags = -g -O0


ui_files := $(shell find ui -type f)
src_files := $(shell find src -type f)

build: $(ui_files) $(src_files)
	mkdir -p $(build_path)
	cp -r ui/assets $(build_path)
	blueprint-compiler compile $(ui_path) > $(build_path)/main.ui
	cp ui/*.css $(build_path)
	gcc src/*.c -o $(application_path) $(build_flags)
clean:
	rm -rf $(build_path)

run: clean build 
	$(build_path)/$(application_name) &

debug:  
	mkdir -p $(build_path)
	cp -r ui/assets $(build_path)
	blueprint-compiler compile $(ui_path) > $(build_path)/main.ui
	cp ui/*.css $(build_path)
	gcc src/*.c -o $(application_path) $(build_flags) $(debug_flags)
	gdb -ex "layout src" $(application_path)
