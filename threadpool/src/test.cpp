#include <iostream>
#include "../include/ThreadPool.h"

int main(){
    ThreadPool pool;
    thread t1([&]{
        for(int i=0;i<100;i++){
            auto thdid=this_thread::get_id();
            pool.AddTask([thdid]{
                cout<<"同步层线程1的线程ID"<<thdid<<endl;
            });
        }
    });
    thread t2([&]{
        for(int i=0;i<100;i++){
            auto thdid=this_thread::get_id();
            pool.AddTask([thdid]{
                cout<<"同步层线程2的线程ID"<<thdid<<endl;
            });
        }
    });
    this_thread::sleep_for(chrono::seconds(2));
    pool.Stop();
    t1.join();
    t2.join();
}