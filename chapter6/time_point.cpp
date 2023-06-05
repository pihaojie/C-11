#include <iostream>
#include <iomanip>
#include <ctime>
#include <chrono>
#include <cstdlib>
using namespace std;
using namespace std::chrono;
int main(){
    system_clock::time_point now=system_clock::now();
    time_t last=system_clock::to_time_t(now-hours(24));
    time_t next=system_clock::to_time_t(now+hours(24));
    cout<<"ago"<<put_time(localtime(&last),"%F %T")<<endl;
    cout<<"next"<<put_time(localtime(&next),"%F %T")<<endl;
    const char *a="3.1415926";
    cout<<a<<endl;
    cout<<atof(a)<<endl;
}