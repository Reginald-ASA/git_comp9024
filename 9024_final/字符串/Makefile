CC = gcc
CCFLAGS = -Wall -Werror -std=c11

KMP : KMP.c
	$(CC) $(CCFLAGS) -o KMP KMP.c

trieTester : trieTester.o Trie.o
	$(CC) -o trieTester trieTester.o Trie.o

trieTester.o : trieTester.c Trie.h
	$(CC) $(CCFLAGS) -std=c11 -c trieTester.c

Trie.o : Trie.c Trie.h
	$(CC) $(CCFLAGS) -std=c11 -c Trie.c

curve : curve.c
	$(CC) $(CCFLAGS) -o curve curve.c -lm

clean:
	rm -f KMP trieTester curve *.o