C++SRC = $(wildcard *.cpp) 
C++OBJ = $(C++SRC:.cpp=.o)

formula: $(C++OBJ)
	g++ -g -o calc $(C++OBJ)

clean:
	rm -f $(C++OBJ)
