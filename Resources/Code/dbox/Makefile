C++SRC = $(wildcard *.cpp) 
C++OBJ = $(C++SRC:.cpp=.o)

donate: $(C++OBJ)
	g++ -g -o calc $(C++OBJ)

clean:
	rm -f $(C++OBJ) calc
