

main: clean
	clang++-9 main.cpp Board.o snowman.o -o main; ./main

clean: 
	clear; rm -f main