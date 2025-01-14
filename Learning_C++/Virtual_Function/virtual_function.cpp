#include<iostream>
using namespace std;
/* 
what is polymorphism?
Polymorphism is a Greek word that means "many-shaped" and it has two main types:
1. Compile-time polymorphism
2. Run-time polymorphism
Compile-time polymorphism is achieved by function overloading and operator overloading.
Run-time polymorphism is achieved by virtual functions.

what is virtual function?
A virtual function is a member function that is declared within a base class and is re-defined(Overriden) by a derived class.
When you refer to a derived class object using a pointer or a reference to the base class, you can call a virtual function for that object and execute the derived class's version of the function.

what is runtime function binding?
Runtime function binding is the process of linking the function call with the function definition.

what is pure virtual function?
A pure virtual function is a function declared in a base class that has no definition relative to the base class.
A pure virtual function is declared by assigning 0 in the declaration.
A class containing a pure virtual function is called an abstract class.

give example of pure virtual function?
class A
{
    public:
        virtual void function1() = 0;
};

what is the use of pure virtual function?
The main use of a pure virtual function is to make a class abstract.
An abstract class is a class that cannot
be instantiated and is designed to be subclassed.
An abstract class is a class that contains at least one pure virtual function.

 */
class parent
{
    public:
        virtual void function1()
        {
            cout<<"parent::function1"<<endl;
        }
        void function2()
        {
            cout<<"parent::function2"<<endl;
        }
};

class child:public parent
{
    public:
        void function1()
        {
            cout<<"child::function1"<<endl;
        }
        void function2()
        {
            cout<<"child::function2"<<endl;
        }
};
int main()
{
    parent *p;
    child c;
    p=&c;
    p->function1();
    return 0;
}