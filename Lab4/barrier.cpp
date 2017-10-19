/*!
 * \author Zoltan Fuzesi - C00197361
 * \version 1.0
 * \date 15/10/2017
 *
 * \copyright GNU Public License
 *
 * \mainpage Barrier
 * \section name_sec Software Engineering
 * Barrier, ConDev - Joseph Kehoe
 * \subsection info_sec Barrier - Description
 * The main method creates fived threads and all of them will call the barrier function.
 * Debug function added to the makefile. to use debugger:
 * 1. open terminal
 * 2. navigate to the folder where Lab4 lab is created
 * 3. Type in : gdb barrierDebug  - to start the debugger function.
 * The Makefile runs the Doxygen to generate the documentation when the project build
 *
 */

#include "Semaphore.h"
#include <iostream>
#include <thread>

static int count;
static int numThreads;
static int loopCounter;

/*!
 * \brief Description of the void barrier function
 * \param theSemaphore is in the parameter list type of thread
 * \details barrier function.
 *  The function is receiving a shared pointer type of thread .
 *  In the function all thread goes trough in the for loop five times and increasing the shared variable by one.
 */
void barrier(std::shared_ptr<Semaphore> theSemaphore)
{
	for(int i=0;i<numThreads;i++){


	  theSemaphore->mutexWait();
	  std::cout << "Mutex wait " <<'\n';
	  count = count + 1;;

	  if(count == numThreads){
	    std::cout << "IF count == numThreads"<<'\n';

	    theSemaphore->barrier2Wait();
	    std::cout << "Barrier 2 wait"<<'\n';

	    theSemaphore->barrier1Signal();
	    std::cout << "Barrier 1 Signal"<<'\n';
	  }

	  std::cout << "count is : " << count <<'\n';
	  theSemaphore->mutexSignal();
	  std::cout << "Mutex signal " <<'\n';
	  std::cout << "Barrier 1 wait " <<'\n';
	  theSemaphore->barrier1Wait();
		theSemaphore->barrier1Signal();
		theSemaphore->barrier1Signal();
		theSemaphore->barrier1Signal();
		theSemaphore->barrier1Signal();
	  std::cout << "Thread left B1 " <<'\n';

	  loopCounter++;
	  std::cout << "Thread " << loopCounter << " Left the first barrier" <<'\n';

	  theSemaphore->mutexWait();
	  count = count - 1;
	  std::cout << "count-- " <<'\n';
	  std::cout << "count is : " << count <<'\n';

	  if(count == 0){

	    std::cout << "count == 0 " <<'\n';
	    theSemaphore->barrier1Wait();
			theSemaphore->barrier2Signal();

	    loopCounter = 0;
	  }
		theSemaphore->mutexSignal();
	  std::cout << "barrier 1 Signal" <<'\n';
	  theSemaphore->barrier1Signal();
	  std::cout << "Barrier 2 wait"<<'\n';
	  theSemaphore->barrier2Wait();//************************************** Barrier 2 ***********************************
	  theSemaphore->barrier2Signal();
	  std::cout << "Loop restart" <<'\n';

	}
}




/*!
 * \brief Description of the main function
 * \param thread threadOne is the first thread
 * \param thread threadTwo is the second thread
 * \param thread threadThree is the third thread
 * \param thread threadFour is the fourth thread
 * \param thread threadFive is the fifth thread
 * \details Main function of barrier
 *  The main method creates five threads and call the barrier functions and passing the threads.
 */
int main(void){

  count = 0;
  numThreads = 5;
  loopCounter = 0;
  std::thread threadOne, threadTwo, threadThree, threadFour, threadFive;

  std::shared_ptr<Semaphore> a( new Semaphore);
  std::shared_ptr<Semaphore> b( new Semaphore);
  std::shared_ptr<Semaphore> c( new Semaphore);
  std::shared_ptr<Semaphore> d( new Semaphore);
  std::shared_ptr<Semaphore> e( new Semaphore);
   std::cout << "Threads are created" << '\n';

   threadOne   = std::thread(barrier,a);
   threadTwo   = std::thread(barrier,b);
   threadThree = std::thread(barrier,c);
   threadFour  = std::thread(barrier,d);
   threadFive  = std::thread(barrier,e);

  threadOne.join();
  threadTwo.join();
  threadThree.join();
	threadFour.join();
	threadFive.join();

  std::cout << "All threads joined" << '\n';
  //std::cout << "Count value is : " << count <<'\n';

  return 0;

}
