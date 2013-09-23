CC = gcc
CFLAGS = 
OBJECTS = build/trie.o build/main.o build/compresor.o build/diccionario_descompresor.o build/descompresor.o build/manejo_bits.o build/Queue.o

build/main : $(OBJECTS)
	$(CC) -o $@ $^ $(CFLAGS)

build/%.o: src/%.c
	$(CC) -c -o $@ $^ $(CFLAGS)

clean :
	rm -f build/main build/*.o


