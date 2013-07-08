prog: map_stuff.o map_lib.o
	gcc -o map_stuff map_stuff.o map_lib.o

map_stuff.o: map_stuff.c
	gcc -c map_stuff.c

map_lib.o: map_lib.c
	gcc -c map_lib.c

