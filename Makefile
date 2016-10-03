.PHONY: all
all: get_int

.PHONY: clean
clean:
	rm -rf build

.PHONY: get_int
get_int: clean src/cs50.cpp src/cs50.h test/get_int.cpp
	mkdir -p build
	clang++ -Isrc -O0 -Wall -Werror -o build/get_int test/get_int.cpp src/cs50.cpp
