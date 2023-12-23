all: utf8

utf8: 
	g++ -Wall -Wpedantic -std=c++14 -march=haswell -o utf8 utf8.c

clean:
	rm -f utf8