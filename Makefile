CFLAGS=-Wall -Wextra -std=c11 -pedantic -O3
LIBS=
SRC=main.c

brainfuck: $(SRC)
	$(CC) $(CFLAGS) -o brainfuck $(SRC) $(LIBS)
