
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
    unsigned int m_uiCountBarrier1;
    unsigned int m_uiCountbarrier2;
    std::mutex m_mutexMutex;
    std::mutex m_mutexBarrier1;
    std::mutex m_mutexBarrier2;
    std::condition_variable m_condition;

public:
    /*!
     * \brief Constructor & Deconstructor
     * The constructor initialise the two member variable (m_uiCountA & m_uiCountB)to Zero;
     */
    Semaphore(unsigned int mutex=1, unsigned int barrier1 = 0,unsigned int barrier2 = 1 ) : m_uiCountMutex(mutex), m_uiCountBarrier1(barrier1) , m_uiCountbarrier2(barrier2) { };
    void mutexWait();
    void mutexSignal();

    void barrier2Wait();
    void barrier2Signal();

    void barrier1Wait();
    void barrier1Signal();


};
