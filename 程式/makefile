all: main.c array.o BinarySearch.o BST.o linkedlist.o hash.o
	gcc main.c array.o BinarySearch.o BST.o linkedlist.o hash.o -o main
array.o: array.c array.h
	gcc -c array.c -o array.o
BinarySearch.o: BinarySearch.c BinarySearch.h
	gcc -c BinarySearch.c -o BinarySearch.o
BST.o: BST.c BST.h
	gcc -c BST.c -o BST.o
linkedlist.o: linkedlist.c linkedlist.h
	gcc -c linkedlist.c -o linkedlist.o
hash.o: hash.c hash.h
	gcc -c hash.c -o hash.o