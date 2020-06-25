CC=gcc
CFLAGS=-Wall

all: build

build: main.c
	$(CC) main.c -o main.o $(CLAGS)

clean: main.o
	rm *.o 
