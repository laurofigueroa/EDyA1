CC = gcc
OBJECTS = trie.o 

main-test : main-test.o $(OBJECTS)
	$(CC) -o main-test main-test.o $(OBJECTS)

main-test.o: trie.h
trie.o: trie.h

clean :
	rm main-test *.o
