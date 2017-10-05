
/*! \class Semaphore.h
    \brief Semaphore declaration

   Uses C++11 features such as mutex and condition variables to implement Semaphore

*/

#include <mutex>
#include <condition_variable>
#include <chrono>
#include <iostream> 
/*!
 * \brief Semaphore.h declaration
 * \param m_mutex Mutual exclusion Mutex lock
 * \param m_condition Condition variable
 * \details Seamphore.h declare the member variables and the functions 
 */

class Semaphore
{
private:
    unsigned int m_uiCount; 
    std::mutex m_mutex;
    std::mutex m_lock;
    std::condition_variable m_condition;
    int m_sharedInt;

public:
    /*!
     * \brief Constructor & Deconstructor
     */
    Semaphore(unsigned int uiCount=0, int m_sharedInt=0) : m_uiCount(uiCount) { };
    void count(std::string msg, int id);
    void Wait();
    void Signal();
    int getSharedInt();

};
