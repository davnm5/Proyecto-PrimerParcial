all: programa

programa: src/programa.c
	gcc -static -c src/list.c -o obj/list.o
	ar -rcs lib/liblista.a obj/list.o
	gcc src/programa.c -o bin/programa -Llib -llista

clean:
	rm -rf programa
