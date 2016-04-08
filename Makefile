INPUT_FILES=main.cpp

all:
	g++ -std=c++0x -Werror $(INPUT_FILES)

gcc:
	g++ -std=c++0x -Wall $(INPUT_FILES)
	
clang:
	clang++ -std=c++11 -Wall $(INPUT_FILES)

clean:
	rm -rf *.out