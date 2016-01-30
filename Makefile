EXE=tldrer
MAIN=main.o

C=gcc
CFLAGS=-W -Wall -Wextra -Werror -std=gnu11 -O3
LINKS=

all: $(EXE) $(C4BOARD) $(C4COL)

$(EXE): $(MAIN)
	$(C) $(CFLAGS) $(MAIN) -o $(EXE)

$(MAIN): main.c
	$(C) $(CFLAGS) -c main.c -o $(MAIN)

clean:
	rm -f *.o tldrer
