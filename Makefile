.PHONY: clean

rogue: rogue.o player.o
	gcc -o rogue rogue.o player.o -lncurses

rogue.o: rogue.c
	gcc -c rogue.c

clean:
	rm -f rogue player *.o

player.o: player.c player.h
	gcc -c player.c