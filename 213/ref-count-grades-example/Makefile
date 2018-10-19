CFLAGS += -std=gnu11 -g
EXES    = grades
OBJS    = refcount.o intlist.o map.o grades.o

all:  $(EXES)
clean:
	rm -f $(OBJS) $(EXES)
tidy:
	rm -f $(OBJS)

grades: grades.o refcount.o intlist.o map.o
