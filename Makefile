all: simuladorLRU

simuladorLRU: src/simuladorLRU.c
	gcc -static -c src/list.c -o obj/list.o
	gcc -static -c src/hash.c -o obj/hash.o
	ar -rcs lib/liblista.a obj/list.o
	ar -rcs lib/libhash.a obj/hash.o
	gcc src/simuladorLRU.c -o bin/simuladorLRU -Llib -llista -lhash
clean:
	rm -rf obj/* bin/* lib/*
