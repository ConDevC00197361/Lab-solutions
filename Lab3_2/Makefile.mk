### Makefile.mk Documentation
EXE = mutex
CC = g++ -g
DOXYGEN = doxygen
PROGRAM = Mutex
CFLAGS =-std=c++11 -pthread -o$(EXE)
CFILES = mutex.cpp Semaphore.cpp
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
	$(DOXYGEN) Doxyfile

debug:
	g++ -g signal.cpp -o mutexDebug

clean:
	rm *.o
