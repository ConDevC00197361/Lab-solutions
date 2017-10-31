// Semaphore.cpp --- 
// 
// Filename: Semaphore.cpp
// Description: 
// Author: Zoltan Fuzesi 
// Maintainer: 
// Created: Tue Oct 31 19:16:32 2017 (+0000)
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



/*!
 * \brief Description of the void mutexWait function
 * \param m_uiCountMutex Counter to the lock
 * \param m_mutexMutex Mutex to the m_uiCountMutex
 * \details Decrease the m_uiCountMutex if more than Zero
 */
void Semaphore::mutexWait()
{
  std::unique_lock< std::mutex > lock(m_mutexMutex);
  m_condition.wait(lock,[&]()->bool{ return m_uiCountMutex>0; });
      --m_uiCountMutex;

}




/*!
 * \brief Description of the void mutexSignal function
 * \param m_uiCountMutex Counter to the lock
 * \param m_mutexMutex Mutex to the m_uiCountMutex
 * \details Decrease the m_uiCountMutex if more than Zero
 */
void Semaphore::mutexSignal()
{
  std::unique_lock< std::mutex > lock(m_mutexMutex);
      ++m_uiCountMutex;
      m_condition.notify_one();

}

/*!
 * \brief Description of the void barrier1Wait function
 * \param m_uiCountBarrier1 Counter to the lock
 * \param m_mutexBarrier1 Mutex to the m_uiCountBarrier1
 * \details Decrease the m_uiCountBarrier1 if more than Zero
 */
 void Semaphore::barrier1Wait()
{
  std::unique_lock< std::mutex > lock(m_mutexBarrier1);
  m_condition.wait(lock,[&]()->bool{ return m_uiCountBarrier1>0; });
      --m_uiCountBarrier1;

}




/*!
 * \brief Description of the void barrier1Signal function
 * \param m_uiCountBarrier1 Counter to the lock
 * \param m_mutexBarrier1 Mutex to the m_uiCountBarrier1
 * \details Decrease the m_uiCountBarrier1 if more than Zero
 */
void Semaphore::barrier1Signal()
{
  std::unique_lock< std::mutex > lock(m_mutexBarrier1);
      ++m_uiCountBarrier1;
      m_condition.notify_all();

}


/*!
 * \brief Description of the void barrier2Wait function
 * \param m_uiCountbarrier2 Counter to the lock
 * \param m_mutexBarrier2 Mutex to the m_uiCountbarrier2
 * \details Decrease the m_uiCountbarrier2 if more than Zero
 */
void Semaphore::barrier2Wait()
{
  std::unique_lock< std::mutex > lock(m_mutexBarrier2);
  m_condition.wait(lock,[&]()->bool{ return m_uiCountBarrier2>0; });
      --m_uiCountBarrier2;

}



/*!
 * \brief Description of the void barrier2Signal function
 * \param m_uiCountbarrier2 Counter to the lock
 * \param m_mutexBarrier2 Mutex to the m_uiCountbarrier2
 * \details Decrease the m_uiCountbarrier2 if more than Zero
 */
void Semaphore::barrier2Signal()
{
  std::unique_lock< std::mutex > lock(m_mutexBarrier2);
      ++m_uiCountBarrier2;
      m_condition.notify_one();

}



// 
// Semaphore.cpp ends here
