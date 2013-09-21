CC = gcc
CFLAGS = -lm
OBJECTS = trie.o main.o compresor.o diccionario_descompresor.o descompresor.o manejo_bits.o

main : $(OBJECTS)
	$(CC) -o main $(OBJECTS) $(CFLAGS)

main.o: main.c trie.c compresor.c trie.h descompresor.c manejo_bits.c
manejo_bits.o: manejo_bits.c
trie.o: trie.c trie.h
inic_dic.o: diccionario_descompresor.c trie.h
descompresor.o: descompresor.c diccionario_descompresor.c trie.h manejo_bits.c
compresor_n.o: compresor.c manejo_bits.c trie.c trie.h

clean :
	rm main *.o 
