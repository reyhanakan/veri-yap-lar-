all: bin compile run

bin:
	@mkdir -p bin

compile: bin
	@g++ -I include/ -o bin/program src/Node.cpp src/ListedList.cpp src/BST.cpp src/main.cpp

run:
	@bin/program