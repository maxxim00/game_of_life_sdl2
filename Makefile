all:
	gcc src/*.c -o output/main -Wall -lm -lSDL2
	./output/main
