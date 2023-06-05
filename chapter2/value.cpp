#include <iostream>
using namespace std;
int g1=0,g2=0,g3=0;
struct A{
    A(){
        cout<<"默认"<<++g1<<endl;
    }
    A(const A& a){
        cout<<"拷贝"<<++g2<<endl;
    }
    ~A(){
        cout<<++g3<<endl;
    }
};
A get(){
    return A();
}
int main(){
    A a=get();
    return 0;
}