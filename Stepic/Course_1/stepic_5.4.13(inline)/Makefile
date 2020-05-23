# Это комментарий, который говорит, что переменная CC указывает компилятор, используемый для сборки
CC=g++
#Это еще один комментарий. Он поясняет, что в переменной CFLAGS лежат флаги, которые передаются компилятору
CFLAGS=-c -Wall 

all: hello

hello: main.o first.o second.o third.o
	$(CC) main.o first.o second.o third.o -o hello

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp
first.o: first.cpp
	$(CC) $(CFLAGS) first.cpp
second.o: second.cpp
	$(CC) $(CFLAGS) second.cpp
third.o: third.cpp
	$(CC) $(CFLAGS) third.cpp

clean:
	rm -rf *.o hello	