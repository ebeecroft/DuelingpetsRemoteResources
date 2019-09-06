C++SRC = $(wildcard *.cpp) 
C++OBJ = $(C++SRC:.cpp=.o)

verify: $(C++OBJ)
	g++ -g -o verify $(C++OBJ)

clean:
	rm -f $(C++OBJ) verify
