### Makefile.mk Documentation

EXE = randezvous
CC = g++
DOXYGEN = doxygen
PROGRAM = randezvous
CFLAGS =-std=c++11 -pthread -o $(EXE)
CFILES = signal2.cpp Semaphore2.cpp
HFILES = Semaphore2.h

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

clean:
	rm *.o
