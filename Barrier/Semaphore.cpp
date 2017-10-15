/*! \class Semaphore.cpp
    \brief A Semaphore Implementation

   Uses C++11 features such as mutex and condition variables to implement Semaphore
*/

#include "Semaphore.h"



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
void Semaphore::barrierWait()
{
  std::unique_lock< std::mutex > lock(m_mutexBarrier);
  m_condition.wait(lock,[&]()->bool{ return m_uiCountBarrier>0; });
      --m_uiCountBarrier;
}



  
/*!
 * \brief Description of the void Signal function
 * \param m_uiCountB Counter to the lock
 * \param m_mutexB Mutex to the m_uiCountB
 * \details Increase the m_uiCount if more than Zero
 */
void Semaphore::barrierSignal()
{
  std::unique_lock< std::mutex > lock(m_mutexBarrier);
      ++m_uiCountBarrier;
      m_condition.notify_one();
}


/*!
 * \brief Description of the void bWait function
 * \param m_uiCountB Counter to the lock
 * \param m_mutexB Mutex to the m_uiCountB
 * \details Decrease the m_uiCount if more than Zero
 */
void Semaphore::mutexAllWait()
{
  std::unique_lock< std::mutex > lock(m_mutexAll);
  m_condition.wait(lock,[&]()->bool{ return m_uiCountAll>0; });
      --m_uiCountAll;
}



  
/*!
 * \brief Description of the void Signal function
 * \param m_uiCountB Counter to the lock
 * \param m_mutexB Mutex to the m_uiCountB
 * \details Increase the m_uiCount if more than Zero
 */
void Semaphore::mutexAllSignal()
{
  std::unique_lock< std::mutex > lock(m_mutexAll);
      ++m_uiCountAll;
      m_condition.notify_one();
}


