/*!
 * \author Zoltan Fuzesi - C00197361
 * \version 1.0
 * \date 02/10/2017
 *
 * \copyright GNU Public License
 *
 * \mainpage Lab 2
 * \section name_sec Software Engineering
 * Lab 3, ConDev - Joseph Kehoe
 * \subsection info_sec Lab 3 - Description
 * The main method creates fived threads and four of them will call the mutexOne and the mutexTwo functions.#
 * In those two functions each thread will goes through in the loop ten times and increase the shared variable
 * value by one. The last thread only will call the printShared Variable function, which is displaying the 
 * shared variable value changed by the threads. The size of the loop can be changed in the mutex functions
 * and that will increase of decrease the shared variable value.
 * The Makefile runs the Doxygen to generate the documentation when the project build  
 *
 */

#include "Semaphore.h"
#include <iostream>
#include <thread>
#include <chrono>

/*!
 * \brief Description of the void mutexOne function
 * \param theSemaphore is in the parameter list type of thread
 * \details MutexOne function.
 *  This function called by the first and the third threads. 
 *  Both threads are goes through the loop ten times and calling the count funtion in the Semaphore class 
 *  and try to increase the value of the shared variable.
 */
void mutexOne(std::shared_ptr<Semaphore> theSemaphore, int count)
{
 std::string msg = "thread " + std::to_string(count);
  for (int i = 0; i < 10; i++)
  {
     theSemaphore->count(msg  , i);
  }
}


/*!
 * \brief Description of the void mutexTwo function
 * \param theSemaphore is in the parameter list type of thread
 * \details MutexTwo function.
 *  This function called by the second and the fourth threads. 
 *  Both threads are goes through the loop ten times and calling the count funtion in the Semaphore class
 *  and try to increase the value of the shared variable.
 */
void mutexTwo(std::shared_ptr<Semaphore> theSemaphore, int count)
{
  std::string msg = "thread " + std::to_string(count);
  for (int i = 0; i < 10; i++)
  {
     theSemaphore->count(msg, i);
  }
}


/*!
 * \brief Description of the void printSharedVariable function
 * \param theSemaphore is in the parameter list type of thread
 * \details printSharedVariable function.
 *  This function called by the fifth threads. 
 *  The thread is calling the getSharedInt function in the Semaphore class
 *  that returning the value of the shared variable and the method printing out the value to the screen.
 */
void printSharedVariable(std::shared_ptr<Semaphore> theSemaphore)
{

  std::cout << "\nThe shared int value is : " << theSemaphore->getSharedInt() << '\n';
}

/*!
 * \brief Description of the main function
 * \param thread threadOne is the first thread
 * \param thread threadTwo is the second thread
 * \param thread threadThree is the third thread
 * \param thread threadFour is the fourth thread
 * \param thread threadFive is the fifth thread
 * \details Main function of mutex 
 *  The main method creates five threads and call the mutexOne & mutexTwo functions with the first four threads.
 *  Because the five threads or shared pointer is a vectore of Semaphores, they are an instances of same Vector object and 
 *  sharing the same meber variables. All the threads are calling the count function in the Semaphore class and increasing 
 *  the value to the shared variableb that is protected with mutex lock in the critical section.
 */
int main(void){

  std::thread threadOne, threadTwo, threadThree, threadFour, threadFive;

   std::shared_ptr<Semaphore> sem( new Semaphore);
 
   threadTwo=std::thread(mutexOne,sem,1);
   threadOne=std::thread(mutexTwo,sem,2);
   threadThree=std::thread(mutexTwo,sem,3);
   threadFour=std::thread(mutexOne,sem,4);
  
  
  
  threadOne.join();
  threadTwo.join();
  threadFour.join();
  threadThree.join();
  threadFive=std::thread(printSharedVariable,sem);
  threadFive.join();
  std::cout << "All threads joined" << '\n';
  
  return 0;
  
}
