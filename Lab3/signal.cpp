/*!
 * \author Zoltan Fuzesi
 * \version 1.0
 * \date 01/10/2017
 * \bug use chrono to delay the thread to give time to another thread to execute command
 *
 * \warning Change/Delete chrono delay
 * 
 * \copyright GNU Public License
 *
 * \mainpage Lab 1
 * \section name_sec Software Engineering
 * Lab 1, ConDev - Josep Kehoe
 * \subsection info_sec Use Makefile to compile Lab 1
 * The Makefile runs the Doxygen to generate the documentation when the project build
 */

#include "Semaphore.h"
#include <iostream>
#include <thread>
#include <chrono>

/*!
 * \brief Description of the void taskOne function
 * \param theSemaphore is in the parameter list type of thread
 * \details This function called by the first thread 
 */
void taskOne(std::shared_ptr<Semaphore> theSemaphore){
  
    std::cout << "Task One - Thread one" << '\n'; 
    theSemaphore->Signal();
  
}


/*!
 * \brief Description of the void taskTwo function
 * \param theSemaphore is in the parameter list type of thread
 * \details This function called by the second thread
 */
void taskTwo(std::shared_ptr<Semaphore> theSemaphore){

  theSemaphore->Wait();
  std::cout << "Task Two - Thread two" << '\n';
   
}


/*!
 * \brief Description of the main function
 * \param thread threadOne is the first thread
 * \param thread threadTwo is the second thread
 * \details Main function creates two threads and call the taskOne & taskTwo functions 
 */
int main(void){
  std::thread threadOne, threadTwo;

   std::shared_ptr<Semaphore> sem( new Semaphore);
 
  threadTwo=std::thread(taskOne,sem);
  threadOne=std::thread(taskTwo,sem);
  
  threadOne.join();
  threadTwo.join();
  std::cout << "All threads joined" << '\n';
  return 0;
  
}
