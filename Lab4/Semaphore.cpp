/*! \class Semaphore.cpp
    \brief A Semaphore Implementation

   Uses C++11 features such as mutex and condition variables to implement Semaphore
*/

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
