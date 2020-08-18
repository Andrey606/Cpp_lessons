# Это комментарий, который говорит, что переменная CC указывает компилятор, используемый для сборки
CC=g++
#Это еще один комментарий. Он поясняет, что в переменной CFLAGS лежат флаги, которые передаются компилятору
CFLAGS=-c -Wall -I $(GOOGLE_TEST_INCLUDE)

GOOGLE_TEST_LIB = gtest
GOOGLE_TEST_INCLUDE = /usr/local/include

LD_FLAGS = -L /usr/local/lib -l $(GOOGLE_TEST_LIB) -l pthread

all: constexpr

constexpr: main.o 
	$(CC) main.o -o constexpr $(LD_FLAGS)

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp


clean:
	rm -rf *.o constexpr