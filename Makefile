CC=gcc
CFLAGS=-Wall -std=gnu99 -O2 -march=native

stable:clean
	$(CC) $(CFLAGS) -lpthread -o jacobi-package main.c utils.c jacobi_thread.c jacobi_sequential.c
debug:clean
	$(CC) $(CFLAGS) -g -lpthread -o jacobi-package main.c utils.c jacobi_thread.c jacobi_sequential.c

clean:
	rm -vfr *~ jacobi-package
