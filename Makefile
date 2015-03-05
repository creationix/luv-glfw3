
all: lglfw.so

deps/libuv/include:
	git submodule update --init deps/libuv

deps/luajit/src:
	git submodule update --init deps/luajit

build/Makefile:
	cmake -H. -Bbuild -GNinja

build/lglfw.a: build/Makefile
	cmake --build build --config Release

lglfw.so: build/lglfw.a
	$(CC) -shared build/lglfw.a -o lglfw.so

clean:
	rm -rf build lglfw.so

test: build/lglfw
	build/luajit tests/run.lua

