### Makefile.mk Documentation
EXE =Barrier
CC = g++ -g
DOXYGEN = doxygen
PROGRAM = Barrier
CFLAGS =-std=c++11 -pthread -o$(EXE)
CFILES = barrier.cpp Semaphore.cpp
HFILES = Semaphore.h

# working simple
#all:$(CFILES) $(HFILES)
#	$(CC) $(CFLAGS) *.cpp -o $(EXE)
#	$(DOXYGEN) Doxyfile

# working more advanced 
all:$(PROGRAM)

#Rule for linking
$(PROGRAM):$(CFILES) $(HFILES)
	$(CC) $(CFLAGS) *.cpp -o $(EXE)
#	$(DOXYGEN) Doxyfile

debug:
	g++ -g signal.cpp -o mutexDebug

clean:
	rm *.o
