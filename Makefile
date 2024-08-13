all:
	cc src/*.c -o output/main -Wall -lm -lSDL2 -lSDL2_ttf
	./output/main
