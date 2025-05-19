application_name = rps_game

ui_path = ui/main.blp
build_path = build
build_flags = `pkg-config --cflags --libs gtk4`

ui_files := $(shell find ui -type f)
src_files := $(shell find src -type f)

build: $(ui_files) $(src_files)
	mkdir -p $(build_path)
	cp -r ui/assets $(build_path)
	blueprint-compiler compile $(ui_path) > $(build_path)/main.ui
	gcc src/*.c -o $(build_path)/$(application_name) $(build_flags)

clean:
	rm -rf $(build_path)

run: build 
	$(build_path)/$(application_name) &