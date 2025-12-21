.PHONY: clean

rogue: rogue.o
	gcc -o rogue rogue.o -lncurses

rogue.o: rogue.c
	gcc -c rogue.c

clean:
	rm -f rogue *.o