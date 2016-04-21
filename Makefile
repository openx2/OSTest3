head = test3.h
srcs = test3.c
objs = test3.o
opts = -g -c
all:	test3
test3:	$(objs)
	gcc $(objs) -o test3
test3.o:	$(srcs) $(head)
	gcc $(opts) $(srcs)
clean:
	rm test3 *.o
