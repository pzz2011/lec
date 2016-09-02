#include <deque>
#include <boost/function.hpp>
#include <boost/thread/mutex.hpp>
#include <boost/thread/locks.hpp>
#include <boost/thread/condition_variable.hpp>
#include <iostream>
#include <cstdio>

class work_queue { 
public:
  typedef boost::function<void()> task_type;

  void push_task(const task_type& task) { 
    boost::unique_lock<boost::mutex> lock(tasks_mutex_);
    tasks_.push_back(task);
    lock.unlock();
    cond_.notify_one();
  }

private: 
  std::deque<task_type> tasks_;
  boost::mutex          tasks_mutex_;
  boost::condition_variable cond_;
}



