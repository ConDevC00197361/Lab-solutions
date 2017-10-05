
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
    unsigned int m_uiCountA;
    unsigned int m_uiCountB; 
    std::mutex m_mutexA;
    std::mutex m_mutexB;
    std::condition_variable m_condition;

public:
    /*!
     * \brief Constructor & Deconstructor
     */
    Semaphore(unsigned int uiCountA=0, unsigned int uiCountB=0 ) : m_uiCountA(uiCountA), m_uiCountB(uiCountB) { };
    void aWait();
    void aSignal();

    void bWait();
    void bSignal();


};
