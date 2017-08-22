# Lines starting with # are comments

# Some variable definitions to save typing later on
CC = gcc
CFLAGS = -std=c99 -Wall -Wextra -pedantic -g

all: ppmIO.o print.o menu.o imageManip.o hw6.o hw6

# Default (first) target -- fill this in
hw6: hw6.o print.o ppmIO.o menu.o imageManip.o

# Links the test executable
unittest: unittest.o ppmIO.o print.o menu.o imageManip.o
	$(CC) $(CFLAGS) -o unittest unittest.o print.o ppmIO.o imageManip.o

# Compiles hw66.cc into an object file
hw6.o: hw6.c print.h ppmIO.h menu.h imageManip.h
	$(CC) $(CFLAGS) -c hw6.c

# Compiles ppmIO.c into an object file
ppmIO.o: ppmIO.c ppmIO.h
	$(CC) $(CFLAGS) -c ppmIO.c

# Compiles print.c into an object file
print.o: print.c print.h
	$(CC) $(CFLAGS) -c print.c

# Compiles menu.c into an object file
menu.o: menu.c menu.h
	$(CC) $(CFLAGS) -c menu.c

# Compiles imageManip.c into an object file
imageManip.o: imageManip.c imageManip.h
	$(CC) $(CFLAGS) -c imageManip.c

# Compiles unittest.c into an object file
unittest.o: unittest.c ppmIO.h print.h menu.h imageManip.h
	$(CC) $(CFLAGS) -c unittest.c

# 'make clean' will remove intermediate & executable files
clean:
	rm -f *.o unittest hw6
