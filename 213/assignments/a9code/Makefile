UTHREAD = .
TARGETS = pc_spinlock pc_mutex_cond smoke traffic phil-skeleton \
	  phil-rightfork phil-ordered phil-random

JUNKF = *.o *~ *.dSYM
WARNINGS = -Wall -Wno-unused-variable -Wno-unused-const-variable

override CFLAGS  += $(WARNINGS) -g -std=gnu11 -I$(UTHREAD)
override LDFLAGS += -pthread

all: $(TARGETS)

pc_spinlock:    pc_spinlock.o    uthread.o
pc_mutex_cond:  pc_mutex_cond.o  uthread.o uthread_mutex_cond.o
smoke:          smoke.o          uthread.o uthread_mutex_cond.o
traffic:        traffic.o        uthread.o uthread_mutex_cond.o
phil-rightfork: phil-rightfork.o uthread.o uthread_mutex_cond.o
phil-ordered:   phil-ordered.o   uthread.o uthread_mutex_cond.o
phil-random:    phil-random.o    uthread.o uthread_mutex_cond.o

pc_spinlock.o:    pc_spinlock.c    uthread.h spinlock.h
pc_mutex_cond.o:  pc_mutex_cond.c  uthread.h uthread_mutex_cond.h
smoke.o:          smoke.c          uthread.h uthread_mutex_cond.h
traffic.o:        traffic.c        uthread.h uthread_mutex_cond.h
phil-rightfork.o: phil-rightfork.c uthread.h uthread_mutex_cond.h
phil-ordered.o:   phil-ordered.c   uthread.h uthread_mutex_cond.h
phil-random.o:    phil-random.c    uthread.h uthread_mutex_cond.h
uthread.o:        uthread.c        uthread.h uthread_util.h
uthread_mutex_cond.o: uthread_mutex_cond.c uthread_mutex_cond.h uthread.h uthread_util.h

tidy:
	-rm -rf $(JUNKF)
clean: tidy
	-rm -rf $(TARGETS)


