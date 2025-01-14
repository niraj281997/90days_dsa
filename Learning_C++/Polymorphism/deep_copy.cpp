#include<iostream>

using namespace std;
/*
 

Summery :
********
Deep copy is slower. However, it’s “safe” it handles pointers and references.
Rather than simply copying over the pointer price, it creates a contemporary copy of the particular knowledge the pointer points to.
So, each of the first and therefore the copy can have pointers that reference completely different underlying knowledge.
If the first object is deleted, the copy can still have a pointer that’s referencing the initial knowledge.
*/

class A
{
    private:
        int x;
        int *p;
    public:

    A(int i = 0)
    {
        x = i;
        p = new int;
        *p = 10;
    }
    A(const A &a)
    {
        x = a.x;
        p = new int;
        *p = *(a.p);
    }
    void change_pointer()
    {
        *p = cin.get();
    }
    void print()
    {
        cout<<"x = "<<x<<endl;
        cout<<"*p = "<<*p<<endl;
    }
  
};

int main()
{
    A a(10);
    a.print();
    A b = a;
    b.change_pointer();
    b.print();
    a.print();
    return 0;
}