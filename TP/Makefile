CC = gcc
CFLAGS = -lm
OBJECTS = trie.o main-test.o compresor.o 

main : $(OBJECTS)
	$(CC) -o main $(OBJECTS) $(CFLAGS)

main-test.o: main-test.c trie.c compresor.c trie.h
trie.o: trie.c trie.h

clean :
	rm main *.o
