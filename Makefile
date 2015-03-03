CC=gcc
CFLAGS="-Wall"

debug:clean
	$(CC) $(CFLAGS) -g -o jacobi-package main.c
stable:clean
	$(CC) $(CFLAGS) -o jacobi-package main.c
clean:
	rm -vfr *~ jacobi-package
