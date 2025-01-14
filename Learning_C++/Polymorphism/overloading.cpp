#include<iostream>
using namespace std;

class A
{
    private:
        int x;
        int y;
    public:
    A(int i = 0, int j = 0)
    {
        x = i;
        y = j;
    }
    void function1(int a, int b)
    {
        cout<<"int a, int b"<<endl;
    }
    void function1(double a, double b)
    {
        cout<<"double a, double b"<<endl;
    }
};
int main()
{
    A a;
    a.function1(1,2);
    a.function1(1.1,2.2);
    
    return 0;
}