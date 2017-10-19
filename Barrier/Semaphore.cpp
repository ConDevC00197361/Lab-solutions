/*! \class Semaphore.cpp
    \brief A Semaphore Implementation

   Uses C++11 features such as mutex and condition variables to implement Semaphore
*/

#include "Semaphore.h"
#include <iostream>



/*!
 * \brief Description of the void aWait function
 * \param m_uiCountA Counter to the lock
 * \param m_mutexA Mutex to the m_uiCountA
 * \details Decrease the m_uiCount if more than Zero
 */
void Semaphore::mutexWait()
{
  std::unique_lock< std::mutex > lock(m_mutexMutex);
  m_condition.wait(lock,[&]()->bool{ return m_uiCountMutex>0; });
      --m_uiCountMutex;
}




/*!
 * \brief Description of the void aSignal function
 * \param m_uiCountA Counter to the lock
 * \param m_mutexA Mutex to the m_uiCountA
 * \details Increase the m_uiCount if more than Zero
 */
void Semaphore::mutexSignal()
{
  std::unique_lock< std::mutex > lock(m_mutexMutex);
      ++m_uiCountMutex;
      m_condition.notify_one();
}

/*!
 * \brief Description of the void bWait function
 * \param m_uiCountB Counter to the lock
 * \param m_mutexB Mutex to the m_uiCountB
 * \details Decrease the m_uiCount if more than Zero
 */
void Semaphore::barrier1Wait()
{
  std::unique_lock< std::mutex > lock(m_mutexBarrier1);
  m_condition.wait(lock,[&]()->bool{ return m_uiCountBarrier1>0; });
      --m_uiCountBarrier1;
}




/*!
 * \brief Description of the void Signal function
 * \param m_uiCountB Counter to the lock
 * \param m_mutexB Mutex to the m_uiCountB
 * \details Increase the m_uiCount if more than Zero
 */
void Semaphore::barrier1Signal()
{
  std::unique_lock< std::mutex > lock(m_mutexBarrier1);
      ++m_uiCountBarrier1;
      m_condition.notify_one();
}


/*!
 * \brief Description of the void bWait function
 * \param m_uiCountB Counter to the lock
 * \param m_mutexB Mutex to the m_uiCountB
 * \details Decrease the m_uiCount if more than Zero
 */
void Semaphore::barrier2Wait()
{
  std::unique_lock< std::mutex > lock(m_mutexBarrier2);
  m_condition.wait(lock,[&]()->bool{ return m_uiCountbarrier2>0; });
      --m_uiCountbarrier2;
}




/*!
 * \brief Description of the void Signal function
 * \param m_uiCountB Counter to the lock
 * \param m_mutexB Mutex to the m_uiCountB
 * \details Increase the m_uiCount if more than Zero
 */
void Semaphore::barrier2Signal()
{
  std::unique_lock< std::mutex > lock(m_mutexBarrier2);
      ++m_uiCountbarrier2;
      m_condition.notify_one();
}
