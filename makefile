all: game

demineur1.o: demineur1.c demineur1.h
	gcc -c demineur1.c -o demineur1.o

demineur2.o: demineur2.c demineur2.h
	gcc -c demineur2.c -o demineur2.o

main.o: main.c demineur1.h demineur2.h
	gcc -c main.c -o main.o

game: main.o demineur1.o demineur2.o
	gcc main.o demineur1.o demineur2.o -o game
