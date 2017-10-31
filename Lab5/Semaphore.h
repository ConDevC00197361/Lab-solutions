/* Semaphore.h --- 
 * 
 * Filename: Semaphore.h
 * Description: 
 * Author: Zoltan Fuzesi 
 * Maintainer: 
 * Created: Tue Oct 31 19:16:54 2017 (+0000)
 * Version: 
 * Package-Requires: ()
 * Last-Updated: 
 *           By: 
 *     Update #: 0
 * URL: 
 * Doc URL: 
 * Keywords: 
 * Compatibility: 
 * 
 */

/* Commentary: 
 * 
 * 
 * 
 */

/* Change Log:
 * 
 * 
 */

/* This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or (at
 * your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with GNU Emacs.  If not, see <http://www.gnu.org/licenses/>.
 */

/* Code: */
#include <mutex>
#include <condition_variable>
#include <iostream>
/*!
 * \brief Semaphore.h declaration
 * \param m_mutexA Mutual exclusion Mutex lock
 * \param m_mutexB Mutual exclusion Mutex lock
 * \param m_uiCountA is a counter for aWait and aSignal functions
 * \param m_uiCountB is a counter for bWait and bSignal functions
 * \param m_condition Condition variable
 * \details Seamphore.h declare the member variables and the functions
 */

class Semaphore
{
private:
    unsigned int m_uiCountMutex;
    unsigned int m_uiCountBarrier1;
    unsigned int m_uiCountBarrier2;
    std::mutex m_mutexMutex;
    std::mutex m_mutexBarrier1;
    std::mutex m_mutexBarrier2;
    std::condition_variable m_condition;
    // std::condition_variable b1_condition;
    // std::condition_variable b2_condition;

public:
    /*!
     * \brief Constructor & Deconstructor
     * The constructor initialise the two member variable (m_uiCountA & m_uiCountB)to Zero;
     */
    Semaphore(unsigned int mutex=1, unsigned int barrier1 = 0,unsigned int barrier2 = 1 ) : m_uiCountMutex(mutex), m_uiCountBarrier1(barrier1) , m_uiCountBarrier2(barrier2) { };
    void mutexWait();
    void mutexSignal();

    void barrier2Wait();
    void barrier2Signal();

    void barrier1Wait();
    void barrier1Signal();


};


/* Semaphore.h ends here */
