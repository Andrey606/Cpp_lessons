all: hello

hello: yaml_parser.o
	g++ yaml_parser.o -o hello -lyaml-cpp

yaml_parser.o: yaml_parser.cpp
	g++ -c yaml_parser.cpp

clean:
	rm -rf *.o hello
