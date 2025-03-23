#include<iostream>
using namespace std;
int main()
{
    int num1,num2;
    cout<<"Enter the number"<<endl;
    cin>>num1>>num2;
    cout<<"Current Value of Num1: "<<num1<<" Value of Num2: "<<num2<<endl;
    num1^=num2^=num1^=num2;
    cout<<"Swap Value of Num1: "<<num1<<" Value of Num2: "<<num2<<endl;
}