#include<iostream>
using namespace std;
bool check_sign(int a,int b)
{
return ((a^b)>=0);
}
int main ()
{

    cout<<"output: "<<check_sign(-1,2)<<endl;
    cout<<"output: "<<check_sign(2,2)<<endl;
    return 0;
}