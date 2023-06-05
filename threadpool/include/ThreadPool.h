#include <functional>
#include <memory>
#include <atomic>
#include "SyncQueue.h"
const int MaxTaskCount=100;

class ThreadPool{
public:
    using Task = function<void()>;

    ThreadPool(int numThreads = thread::hardware_concurrency()):m_queue(MaxTaskCount){
        Start(numThreads);
    }
    ~ThreadPool(void){
        Stop();
    }

    void Stop(){
        //保证多线程情况下只调用一次
        call_once(m_flag,[this]{StopThreadGroup();});
    }
    void AddTask(Task&& task){
        m_queue.Put(forward<Task>(task));
    }
    void AddTask(const Task& task){
        m_queue.Put(task);
    }
    
private:
    void Start(int numThreads){
        m_running = true;
        for(int i=0;i<numThreads;i++){
            m_threadgroup.push_back(make_shared<thread>(&ThreadPool::RunInThread,this));
        }
    }

    void RunInThread(){
        while(m_running){
            list<Task> list;
            m_queue.Take(list);
            for(auto& task:list){
                if(!m_running)return;
                task();
            }
        }
    }
    void StopThreadGroup(){
        m_queue.Stop();
        m_running=false;
        for(auto thread:m_threadgroup){
            if(thread){
                thread->join();
            }
        }
        m_threadgroup.clear();
    }

    list<shared_ptr<thread>> m_threadgroup; //处理任务的线程组
    SyncQueue<Task> m_queue;//同步队列
    atomic_bool m_running;  //是否停止的标志
    once_flag m_flag;
};
