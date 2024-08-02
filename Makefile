all:
	cc src/*.c -o output/main -Wall -lm -lSDL2
	./output/main
