// procon.cpp --- 
// 
// Filename: procon.cpp
// Description: 
// Author: Zoltan Fuzesi 
// Maintainer: 
// Created: Tue Oct 31 19:16:06 2017 (+0000)
// Version: 
// Package-Requires: ()
// Last-Updated: 
//           By: 
//     Update #: 0
// URL: 
// Doc URL: 
// Keywords: 
// Compatibility: 
// 
// 

// Commentary: 
// 
// 
// 
// 

// Change Log:
// 
// 
// 
// 
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or (at
// your option) any later version.
// 
// This program is distributed in the hope that it will be useful, but
// WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// General Public License for more details.
// 
// You should have received a copy of the GNU General Public License
// along with GNU Emacs.  If not, see <http://www.gnu.org/licenses/>.
// 
// 

// Code:

#include "Semaphore.h"
#include <iostream>
#include <thread>

static int count;
static int numThreads;
static int loopCounter;


/*!
 * \brief Description of the main function
 * 
 */
int main(void){
  
  //std::thread threadOne, threadTwo, threadThree, threadFour, threadFive;

  //std::shared_ptr<Semaphore> a( new Semaphore);
  
  //threadOne.join();
  

  std::cout << "All threads joined" << '\n';
  //std::cout << "Count value is : " << count <<'\n';

  return 0;

}

// 
// procon.cpp ends here
