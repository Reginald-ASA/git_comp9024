CC = gcc
CCFLAGS = -Wall -Werror -std=c11

rbt : RBTree.o RBTester.o
	$(CC) -o rbt RBTester.o RBTree.o

treeLab : treeLab.o BST.o queue.o
	$(CC) -o treeLab treeLab.o BST.o queue.o -lm

treeLab.o : treeLab.c BST.h
	$(CC) $(CCFLAGS) -c treeLab.c

RBTester.o : RBTester.c RBTree.h
	$(CC) $(CCFLAGS) -c RBTester.c

BST.o : BST.c BST.h queue.h
	$(CC) $(CCFLAGS) -c BST.c

RBTree.o : RBTree.c RBTree.h
	$(CC) $(CCFLAGS) -c RBTree.c

queue.o : queue.c queue.h
	$(CC) $(CCFLAGS) -c queue.c

clean:
	rm -f rbt treeLab *.o