// Copyright (c) 2016 The Bitcoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef BITCOIN_THREADINTERRUPT_H
#define BITCOIN_THREADINTERRUPT_H

/*#include <atomic>
#include <chrono>
#include <condition_variable>
#include <mutex>
*/
#include <boost/thread.hpp>

namespace std
{
   using boost::mutex;
   using boost::recursive_mutex;
   using boost::lock_guard;
   using boost::condition_variable;
   using boost::unique_lock;
   using boost::thread;
}
/*
    A helper class for interruptible sleeps. Calling operator() will interrupt
    any current sleep, and after that point operator bool() will return true
    until reset.
*/
class CThreadInterrupt
{
public:
    explicit operator bool() const;
    void operator()();
    void reset();
    bool sleep_for(std::chrono::milliseconds rel_time);
    bool sleep_for(std::chrono::seconds rel_time);
    bool sleep_for(std::chrono::minutes rel_time);

private:
    std::condition_variable cond;
    std::mutex mut;
    std::atomic<bool> flag;
};

#endif //BITCOIN_THREADINTERRUPT_H
