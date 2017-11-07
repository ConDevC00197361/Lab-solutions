///* main.cpp --- 
// * 
// * Filename: Barrier.h
// * Description: 
// * Author: Zoltan Fuzesi 
// * Maintainer: 
//// LICENSE :  GPLv3
// * Created: Mon Nov  6 09:05:06 2017 (+0000)
// * Version: 
// * Package-Requires: ()
// * Last-Updated: 
// *           By: 
// *     Update #: 0
// * URL: 
// * Doc URL: 
// * Keywords: 
// * Compatibility: 
// * 
// */
//
///* Commentary: 
// * 
// * 
// * 
// */
//
///* Change Log:
// * 
// * 
// */
//
///* This program is free software: you can redistribute it and/or modify
// * it under the terms of the GNU General Public License as published by
// * the Free Software Foundation, either version 3 of the License, or (at
// * your option) any later version.
// * 
// * This program is distributed in the hope that it will be useful, but
// * WITHOUT ANY WARRANTY; without even the implied warranty of
// * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// * General Public License for more details.
// * 
// * You should have received a copy of the GNU General Public License
// * along with GNU Emacs.  If not, see <http://www.gnu.org/licenses/>.
// */
//
///* Code: */
#include "Barrier.h"
#include <iostream>
#include <thread>
#include <vector>
#include <list>
using namespace std;

static int NUMBER_OF_LOOP = 5;

/*!
 * \brief Description of the void barrier function
 * \param BarrierObj is in the parameter list is type of thread-barrier object
 * \details barrier function.
 *  The function is receiving a shared pointer type of thread-barrier object .
 *  The BarrierObj (threads) are calling the barrierOne after the barrierTwo function, what is a
 *  public method in the barrier class. 
 *  In the function all thread goes trough in the for loop NUMBER_OF_LOOP times.
 */
void barrier(std::shared_ptr<Barrier> BarrierObj){
  
    for(int i=0;i<NUMBER_OF_LOOP;i++){
        BarrierObj->barrierOne();
        cout << "Thread left barrier one " << "\n";
        BarrierObj->barrierTwo();
        cout << "Thread left barrier two " << "\n";
        cout << "Restart loop " << i << "\n";
    }
}

/*!
 * \brief Description of the main method
 * \param numberOfThreadsInTheBarrier is a number of passing to the barrier class
 * represents the threads are going through the barriers
 * \details barrier function.
 * \param shared_ptr<Barrier>barrierObj is a shared pointer of a Barrier object
 * \param vector<std::thread>threadVector is a vector to create threads.
 *  The for loop creates a numberOfThreadsInTheBarrier threads and push into the vector and the
 * threads are calling the barrier function at creation time
 */
int main(void){
    int numberOfThreadsInTheBarrier = 5;
    
    std::shared_ptr<Barrier> barrierObj(new Barrier(numberOfThreadsInTheBarrier));
    std::vector<std::thread> threadVector;

    for (int i = 0; i < numberOfThreadsInTheBarrier; i++) {
      cout << "Loop " << i << "\n";
      threadVector.push_back(std::thread(barrier, barrierObj));
    }
    
    for (auto& th : threadVector) 
    {
        th.join();
    }

    cout << "All threads are finished!!!" << "\n";
    return 0;
}

///* main.cpp ends here */