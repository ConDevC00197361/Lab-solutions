### Makefile.mk Documentation
EXE =Producer
CC = g++ -g
DOXYGEN = doxygen
PROGRAM = Producer
CFLAGS =-std=c++11 -pthread -o$(EXE)
CFILES = main.cpp Semaphore.cpp SafeBuffer.cpp
HFILES = Semaphore.h SafeBuffer.h

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
	g++ -g signal.cpp -o procon

clean:
	rm *.o
