all: libfakemac.so

CFLAGS = -Wall -Wextra -Werror -fpic

libfakemac.o: libfakemac.c

libfakemac.so: libfakemac.o
	gcc $(CFLAGS) -shared -ldl -o libfakemac.so libfakemac.o
