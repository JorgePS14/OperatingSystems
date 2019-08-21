libhello.o: LibHello.c
	gcc -c LibHello.c
hello: Hello.c LibHello.o
	gcc Hello.c LibHello.o -o Hello
test: hello
	./Hello Jorge Luis Memo Diego
