# Это комментарий, который говорит, что переменная CC указывает компилятор, используемый для сборки
CC=g++
#Это еще один комментарий. Он поясняет, что в переменной CFLAGS лежат флаги, которые передаются компилятору
CFLAGS=-c -Wall

all: constexpr

constexpr: main.o 
	$(CC) main.o -o constexpr

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp


clean:
	rm -rf *.o constexpr