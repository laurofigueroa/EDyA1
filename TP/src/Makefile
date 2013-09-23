CC = gcc
CFLAGS = 
OBJECTS = trie.o main.o compresor.o diccionario_descompresor.o descompresor.o manejo_bits.o Queue.o

main : $(OBJECTS)
	$(CC) -o main $(OBJECTS) $(CFLAGS)

main.o: main.c trie.c compresor.c trie.h descompresor.c manejo_bits.c
Queue.o: Queue.c Queue.h
manejo_bits.o: manejo_bits.c
trie.o: trie.c trie.h
diccionario_descompresor.o: diccionario_descompresor.c trie.h
descompresor.o: descompresor.c diccionario_descompresor.c trie.h manejo_bits.c
compresor.o: compresor.c manejo_bits.c trie.c trie.h Queue.c

clean :
	rm main *.o 
