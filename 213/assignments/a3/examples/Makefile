CFLAGS = -std=gnu11 -g
EXES   = e1 e2 e3 e4 example-global-static example-global-dynamic
OBJS   = example-global-static.o example-global-dynamic.o e1.o e2.o e3.o e4.o

all:  $(EXES)
clean:
	rm -f $(OBJS) $(EXES)
tidy:
	rm -f $(OBJS)

example-global-static: example-global-static.o
example-global-dynamic: example-global-dynamic.o
e1: e1.o
e2: e2.o
e3: e3.o
e4: e4.o
