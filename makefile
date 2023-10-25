#Makefile para crear librerias dinamicas

nombre = ESTDLIB

CC = clang
CFlags = -Wall -std=c11 -pedantic -pedantic-errors -O3
Libs = 
SOFlags = -fPIC -shared

all: libinstall

libinstall: solib
	sudo cp ./build/lib$(nombre).so /usr/local/lib/lib$(nombre).so
	sudo cp ./*.h /usr/local/include/
solib: build
	$(CC) $(CFlags) $(SOFlags) -o./build/lib$(nombre).so ./*c $(Libs)
rebuild: build
	rm ./build/lib$(nombre).so
	$(CC) $(CFlags) $(SOFlags) -o./build/lib$(nombre).so ./*c $(Libs)
build:
	mkdir build