/*!
 * \author Zoltan Fuzesi - C00197361
 * \version 1.0
 * \date 02/10/2017
 *
 * \copyright GNU Public License
 *
 * \mainpage Lab 3
 * \section name_sec Software Engineering
 * Lab 3, ConDev - Joseph Kehoe
 * \subsection info_sec Lab 3 - Description
 * The main method creates fived threads and four of them will call the mutexOne and the mutexTwo functions.#
 * In those two functions each thread will goes through in the loop ten times and increase the shared variable
 * value by one. The last thread only will call the printShared Variable function, which is displaying the 
 * shared variable value changed by the threads. The size of the loop can be changed in the mutex functions
 * and that will increase of decrease the shared variable value.
 * Debug function added to the makefile. to use debugger: 
 * 1. open terminal
 * 2. navigate to the folder where mutex lab is created
 * 3. Type in : gdb mutex  - to start the debugger function.
 * The Makefile runs the Doxygen to generate the documentation when the project build  
 *
 */

#include "Semaphore.h"
#include <iostream>
#include <thread>

static int count;
static int numThreads;
static int threadFinishCount;

/*!
 * \brief Description of the void mutexOne function
 * \param theSemaphore is in the parameter list type of thread
 * \details MutexOne function.
 *  The function is receiving a shared pointer type of thread and the pointer to the shared variable.
 *  In the function the thread goes trough in the for loop ten times and increasing the shared variable by one.
 */
void mutexOne(std::shared_ptr<Semaphore> theSemaphore)
{
	std::cout << "Number of threads : " << count << '\n';
	for(int i=0;i<numThreads;i++){
		  theSemaphore->mutexWait();
		  count++;
		  std::cout << "Count is  : " << count << '\n';
		  if(count == numThreads)
		  {
		  	//theSemaphore->mutexAllWait();
		    theSemaphore->barrierSignal();
		    //theSemaphore->mutexAllSignal();
		  }
		  std::cout << "After if statement" << '\n';
		  theSemaphore->mutexSignal();
		  std::cout << "mutexSignal next" << '\n';
		  theSemaphore->barrierWait();
		  theSemaphore->barrierSignal();
		  threadFinishCount++;
		  std::cout << "Thread finish : " << threadFinishCount << '\n';
		 
		  
		  if(threadFinishCount != numThreads )
		  {
		  	threadFinishCount = 0;
		  	count = 0;
		  	for(int x =0; x < numThreads;x++){
		  		theSemaphore->mutexAllSignal();	
		  	}
		  	
		  	
		  }
		  else{
		  	theSemaphore->mutexAllWait();
		  	
		  }
		   

	}
}




/*!
 * \brief Description of the main function
 * \param thread threadOne is the first thread
 * \param thread threadTwo is the second thread
 * \param thread threadThree is the third thread
 * \param thread threadFour is the fourth thread
 * \param thread threadFive is the fifth thread
 * \details Main function of mutex 
 *  The main method creates two threads and call the mutexOne & mutexTwo functions and passing the threads and the 
 *  shared int (count) variable addres to the functions.
 */
int main(void){

  count = 0;
  numThreads = 3;
  threadFinishCount = 0;
  std::thread threadOne, threadTwo, threadThree;

   std::shared_ptr<Semaphore> sem( new Semaphore);
   std::cout << "Threads are created" << '\n';
   threadTwo=std::thread(mutexOne,sem);
   threadOne=std::thread(mutexOne,sem);
   threadThree=std::thread(mutexOne,sem);


   
  
  threadOne.join();
  threadTwo.join();
  threadThree.join();

  std::cout << "All threads joined" << '\n';
  std::cout << "Count value is : " << count <<'\n';
  
  return 0;
  
}
