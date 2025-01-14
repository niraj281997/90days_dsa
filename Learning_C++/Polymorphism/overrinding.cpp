#include<iostream>
using namespace std;

class A
{
    public:
        void function1()
        {
            cout<<"A::function1"<<endl;
        }
        void function2()
        {
            cout<<"A::function2"<<endl;
        }
};
class B:protected A
{
    public:
        void function1()
        {
            cout<<"B::function1"<<endl;
        }
        void function2()
        {
            cout<<"B::function2"<<endl;
        }
};
int main()
{
    A a;
    B b;
    B *ptr = &b;
    ptr->function1();
    ptr->function2();
   //b.function1();

    return 0;
}
