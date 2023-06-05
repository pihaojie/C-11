#include<iostream>
using namespace std;
void func(auto a){
    cout<<a<<endl;
}
template<typename T>
struct bar{};
struct fo{
    //auto a=1;
};
int main(){
    //auto a[10];
    func(1.1);
    bar<int> b;
    //bar<auto> b;
}