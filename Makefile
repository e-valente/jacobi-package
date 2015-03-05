CC=gcc
CFLAGS=-Wall -std=gnu99

debug:clean
	$(CC) $(CFLAGS) -g -o jacobi-package main.c utils.c jacobi-sequential.c
stable:clean
	$(CC) $(CFLAGS) -o jacobi-package main.c utils.c jacobi-sequential.c
clean:
	rm -vfr *~ jacobi-package
