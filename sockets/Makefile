CXX = g++
CXXFLAGS = -Wall -g -std=c++2a

make all: server client

server: objs/server.o
	$(CXX) $(CXXFLAGS) -o bin/server.out objs/server.o

objs/server.o: src/server.cpp
	$(CXX) $(CXXFLAGS) -c src/server.cpp -o objs/server.o

client: objs/client.o
	$(CXX) $(CXXFLAGS) -o bin/client.out objs/client.o

objs/client.o: src/client.cpp
	$(CXX) $(CXXFLAGS) -c src/client.cpp -o objs/client.o

clean:
	rm -rf objs/*.o bin/*.out
