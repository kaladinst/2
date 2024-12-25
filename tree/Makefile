all: bin/main

bin/main: src/List.cpp src/main.cpp src/Tree.cpp src/TreeNode.cpp
	mkdir -p bin
	g++ src/main.cpp src/List.cpp src/Tree.cpp src/TreeNode.cpp -o bin/main

clean:
	rm -f src/*.o bin/main