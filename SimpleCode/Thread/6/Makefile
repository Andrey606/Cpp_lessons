# Это комментарий, который говорит, что переменная CC указывает компилятор, используемый для сборки
CC=g++
#Это еще один комментарий. Он поясняет, что в переменной CFLAGS лежат флаги, которые передаются компилятору
CFLAGS=-c -Wall 
CLIBS=-lpthread

all:
	g++ main.cpp SimpleTimer.cpp -o hello

hello: main.o SimpleTimer.o
	$(CC) main.o SimpleTimer.o -o hello 

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp  $(CLIBS)
SimpleTimer.o: SimpleTimer.cpp
	$(CC) $(CFLAGS) SimpleTimer.cpp

clean:
	rm -rf *.o hello	