CC=gcc
CFLAGS=-Wall -std=gnu99 -O2 -march=native

stable:clean
	$(CC) $(CFLAGS) -o jacobi-package main.c utils.c jacobi-sequential.c
debug:clean
	$(CC) $(CFLAGS) -g -o jacobi-package main.c utils.c jacobi-sequential.c

clean:
	rm -vfr *~ jacobi-package
