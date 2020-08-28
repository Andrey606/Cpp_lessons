# Это комментарий, который говорит, что переменная CC указывает компилятор, используемый для сборки
CC=g++
#Это еще один комментарий. Он поясняет, что в переменной CFLAGS лежат флаги, которые передаются компилятору
CFLAGS=-c -Wall

all: hello

hello: main.o  devices.o
	$(CC) main.o devices.o -o hello

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp

devices.o: devices.cpp
	$(CC) $(CFLAGS) devices.cpp
	

clean:
	rm -rf *.o hello