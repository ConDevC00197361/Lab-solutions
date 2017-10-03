/*!
 * \author Zoltan Fuzesi - C00197361
 * \version 1.0
 * \date 02/10/2017
 *
 * \copyright GNU Public License
 *
 * \mainpage Lab 2
 * \section name_sec Software Engineering
 * Lab 1, ConDev - Joseph Kehoe
 * \subsection info_sec Lab 1 - Description
 * The Makefile runs the Doxygen to generate the documentation when the project build  
 *
 */

#include "Semaphore2.h"
#include <iostream>
#include <thread>
#include <chrono>

/*!
 * \brief Description of the void taskOne function
 * \param theSemaphore is in the parameter list type of thread
 * \details This function called by the first thread 
 */
void taskOne(std::shared_ptr<Semaphore2> theSemaphore)
{

  for (int i = 0; i < 10; i++)
  {
     theSemaphore->count("thread One", i);
  }
  //theSemaphore->Signal();
  
}


/*!
 * \brief Description of the void taskTwo function
 * \param theSemaphore is in the parameter list type of thread
 * \details This function called by the second thread
 */
void taskTwo(std::shared_ptr<Semaphore2> theSemaphore)
{
  for (int i = 0; i < 10; i++)
  {
     theSemaphore->count("thread Two", i);
  }
  //theSemaphore->Signal();
   
}

void printInt(std::shared_ptr<Semaphore2> theSemaphore)
{
  //theSemaphore->Wait();
  std::cout << "\nThe shared int value is : " << theSemaphore->getSharedInt() << '\n';
}

/*!
 * \brief Description of the main function
 * \param thread threadOne is the first thread
 * \param thread threadTwo is the second thread
 * \details Main function creates two threads and call the taskOne & taskTwo functions 
 */
int main(void){
  
  std::thread threadOne, threadTwo, threadThree, threadFour, threadFive;

   std::shared_ptr<Semaphore2> sem( new Semaphore2);
 
  threadTwo=std::thread(taskOne,sem);
  threadOne=std::thread(taskTwo,sem);
  threadFour=std::thread(taskOne,sem);
  threadFive=std::thread(taskTwo,sem);
  
  
  threadOne.join();
  threadTwo.join();
  threadFour.join();
  threadFive.join();
  threadThree=std::thread(printInt,sem);
  threadThree.join();
  std::cout << "All threads joined" << '\n';
  
  return 0;
  
}
