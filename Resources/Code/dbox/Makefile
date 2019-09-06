C++SRC = $(wildcard *.cpp) 
C++OBJ = $(C++SRC:.cpp=.o)

donate: $(C++OBJ)
	g++ -g -o calz $(C++OBJ)

clean:
	rm -f $(C++OBJ) calz
