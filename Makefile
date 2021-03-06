all: clean prog shared

prog: map_stuff.o map_lib.o
	gcc -o map_stuff map_stuff.o map_lib.o

shared: map_lib.o-shared
	gcc -o libMapStuff.so map_lib.o -fPIC -g -shared -DSHARED

map_stuff.o: map_stuff.c
	gcc -c map_stuff.c

map_lib.o: map_lib.c
	gcc -c map_lib.c

map_lib.o-shared: map_lib.c
	gcc -c map_lib.c -fPIC -DSHARED

clean:
	rm -f *.o
	rm -f *.so

