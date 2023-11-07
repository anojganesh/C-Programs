prog: prog.o myfuncs.o
        gcc -o prog prog.o myfuncs.o
prog.o: prog.c myfuncs.h
        gcc -c prog.c
myfuncs.o: myfuncs.c myfuncs.h
        gcc -c myfuncs.c
