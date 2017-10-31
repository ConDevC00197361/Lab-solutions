Lab Four – Reusable Barrier Class
Create a reusable barrier class that employs the Semaphore Class. You must  include the Doxygen settings file and a Makefile.
The makefile must now also include a “clean” rule that deletes all .o files from the project and a debug option that allows use of the gdb debugger. Add the -Wall flag to the list of compiler flags sued by the Debug rule. 

All files should now begin with a file comment that contains the following information:
1. Author Name
2. Date of File Created
3. Licence Employed
All code files will include suitable Doxygen comments.  The Makefile will also include comments explaining its purpose.
A README file must also be included.  This is a text file that describes what this solution does, who the author is and the licence employed.  It should contain instructions on how to compile the file and run it.
The main function should show the barrier in acton in such a way that it is clear that it works.
Files in this Lab
1. Semaphore.cpp
2. Semaphore.h
3. Barrier.cpp
4. Barrier.h
5. main.cpp
6. Doxyfile
7. README
8. Makefile
Lab 5 – Producer/Consumer
Create a program that has two parts.  A producer and a consumer.

The producer generates random characters from ‘a’ to ‘z’ at random intervals (between 0 and 1 second in length). It adds these to a thread safe buffer that has a finite holding capacity of N characters. It generates a preset number of characters (determined at runtime) and when it has finished it add an ‘X’ character to the buffer and exits.
The consumer takes these letters from the buffer at random time intervals (between 0 and 1 second in length) and records how many of each letter it consumes. Once it sees an ‘X’ in the buffer it adds its character count to a central buffer and exits.
Files in this Lab
1. Semaphore.cpp
2. Semaphore.h
3. SafeBuffer.cpp
4. SafeBuffer.h
5. main.cpp
6. Doxyfile
7. README
8. Makefile
The main file should demonstrate your producer consumer implementation in action by creating a  number of consumers and producers and showing them in action.
All files must include suitable documentation. The Makefile must contain a rule (‘doc’) that runs the Doxygen program and generates the documentation.
Edit your emacs settings so that it now automatically generates headers for your code files.  e.g. see https://www.emacswiki.org/emacs/AutomaticFileHeaders

