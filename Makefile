CXX=g++
CXXFLAGS=-Wall -g3
LDFLAGS=-lm

main: main.cpp 
	$(CXX) $(CXXFLAGS) -o main main.cpp $(LDFLAGS)

.PHONY: clean
clean:
	rm -fr *.0 main