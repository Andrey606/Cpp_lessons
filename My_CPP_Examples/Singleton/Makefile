all: hello

hello: Singleton.o
	g++ Singleton.o -o hello

Singleton.o: Singleton.cpp
	g++ -c Singleton.cpp

clean:
	rm -rf *.o hello
