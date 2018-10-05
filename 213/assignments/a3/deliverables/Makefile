CFLAGS += -std=gnu11 -g -Wall
EXES = q1 q2 bubble_sort_dynamic bubble_sort_awesome
OBJS = q1.o q2.o bubble_sort_dynamic.o bubble_sort_awesome.o

all: $(EXES)
clean:
	rm -f $(OBJS) $(EXES)
q1: q1.o
q1.o: q1.c
q2: q2.o
q2.o: q2.c
bubble_sort_dynamic: bubble_sort_dynamic.o
bubble_sort_dynamic.o: bubble_sort_dynamic.c
bubble_sort_awesome: bubble_sort_awesome.o
bubble_sort_awesome.o: bubble_sort_awesome.c
