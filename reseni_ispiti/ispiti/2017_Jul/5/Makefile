5: 5.o stabla.o
	gcc 5.o stabla.o -o 5

5.o: 5.c
	gcc -c 5.c -Wall -Wextra 

stabla.o: stabla.c
	gcc -c stabla.c -Wall -Wextra

.PHONY: del

del:
	rm -f *.o