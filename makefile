compile: linkedlist.c
	gcc linkedlist.c -o linkedlist
clean:
	rm *~
	rm *#
run: list
	./linkedlist
