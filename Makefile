CXX=g++
CXXFLAGS=-fopenmp
LDFLAGS=-lm
main.o: main.cpp
    $(CXX) $(CXXFLAGS) main.cpp -o main.o $(LDFLAGS)
.PHONY: clean
clean:
    rm -fr *.0 main
