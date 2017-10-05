/*! \class Semaphore.cpp
    \brief A Semaphore Implementation

   Uses C++11 features such as mutex and condition variables to implement Semaphore
*/

#include "Semaphore.h"

/*!
 * \brief Description of the void Wait function
 * \param m_uiCount Counter to the lock
 * \details Decrease the m_uiCount if more than Zero
 */
void Semaphore::Wait(){

  
  std::unique_lock< std::mutex > lock(m_mutex);
  m_condition.wait(lock,[&]()->bool{ return m_uiCount>0; }
);
      --m_uiCount;
}


/*!
 * \brief Description of the boolean Wait function
 * \param m_uiCount Counter to the lock
 * \details Decrease the m_uiCount if more than Zero
 */
template< typename R,typename P >
bool Semaphore::Wait(const std::chrono::duration<R,P>& crRelTime)
{
  std::unique_lock< std::mutex > lock(m_mutex);
      if (!m_condition.wait_for(lock,crRelTime,[&]()->bool{ return m_uiCount>0; })){
	return false;
      }
      --m_uiCount;
      return true;
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
