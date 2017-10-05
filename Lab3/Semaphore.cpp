/*! \class Semaphore.cpp
    \brief A Semaphore Implementation

   Uses C++11 features such as mutex and condition variables to implement Semaphore
*/

#include "Semaphore.h"


/*!
 * \brief Description of the Shared Method
 * \param m_lock Mutex lock
 * \details m_lock allows only one thread access the cout line at a time
 */

void Semaphore::count(std::string msg, int id)
 {
 	 m_lock.lock();
 	 std::cout <<  msg  << " Shared value is : " << m_sharedInt << std::endl;
 	 m_sharedInt++;
 	 m_lock.unlock();
 }
/*!
 * \brief Description of the void Wait function
 * \param m_uiCount Counter to the lock
 * \details Decrease the m_uiCount if more than Zero
 */
void Semaphore::Wait()
{
  std::unique_lock< std::mutex > lock(m_mutex);
  m_condition.wait(lock,[&]()->bool{ return m_uiCount>0; });
      --m_uiCount;
}



  
/*!
 * \brief Description of the void Signal function
 * \param m_uiCount Counter to the lock
 * \details Increase the m_uiCount if more than Zero
 */
void Semaphore::Signal()
{
  std::unique_lock< std::mutex > lock(m_mutex);
      ++m_uiCount;
      m_condition.notify_one();
}

int Semaphore::getSharedInt()
{
	return m_sharedInt;
}
