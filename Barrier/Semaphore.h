
/*! \class Semaphore.h
    \brief Semaphore declaration

   Uses C++11 features such as mutex and condition variables to implement Semaphore

*/

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
    unsigned int m_uiCountBarrier; 
    unsigned int m_uiCountAll;
    std::mutex m_mutexMutex;
    std::mutex m_mutexBarrier;
    std::mutex m_mutexAll;
    std::condition_variable m_condition;

public:
    /*!
     * \brief Constructor & Deconstructor
     * The constructor initialise the two member variable (m_uiCountA & m_uiCountB)to Zero;
     */
    Semaphore(unsigned int m_uiCountMutex=1, unsigned int m_uiCountBarrier = 0,unsigned int m_uiCountAll = 1 ) : m_uiCountMutex(m_uiCountMutex), m_uiCountBarrier(m_uiCountBarrier) , m_uiCountAll(m_uiCountAll) { };
    void mutexWait();
    void mutexSignal();

    void mutexAllWait();
    void mutexAllSignal();

    void barrierWait();
    void barrierSignal();


};
