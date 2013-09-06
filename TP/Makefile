CC = gcc
CFLAGS = -lm
OBJECTS = trie.o main-test.o compresor.o inic_dic.o descompresor.o

main : $(OBJECTS)
	$(CC) -o main $(OBJECTS) $(CFLAGS)

main-test.o: main-test.c trie.c compresor.c trie.h descompresor.c
trie.o: trie.c trie.h
inic_dic.o: inic_dic.c trie.h
descompresor.o: descompresor.c inic_dic.c trie.h
clean :
	rm main *.o
