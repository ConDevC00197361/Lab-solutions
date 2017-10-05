### Makefile.mk Documentation
EXE = mutex
CC = g++
DOXYGEN = doxygen
PROGRAM = Mutex
CFLAGS =-std=c++11 -pthread -o$(EXE)
CFILES = signal.cpp Semaphore.cpp
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
	g++ -g signal.cpp -o signalDebug

clean:
	rm *.o
