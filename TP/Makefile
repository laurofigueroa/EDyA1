CC = gcc
CFLAGS = -lm
OBJECTS = trie.o main-test.o compresor_n.o inic_dic.o descompresor.o manejo_bits.o

main : $(OBJECTS)
	$(CC) -o main $(OBJECTS) $(CFLAGS)

main-test.o: main-test.c trie.c compresor_n.c trie.h descompresor.c manejo_bits.c
manejo_bits.o: manejo_bits.c
trie.o: trie.c trie.h
inic_dic.o: inic_dic.c trie.h
descompresor.o: descompresor.c inic_dic.c trie.h manejo_bits.c
compresor_n.o: compresor_n.c manejo_bits.c trie.c trie.h

clean :
	rm main *.o 
