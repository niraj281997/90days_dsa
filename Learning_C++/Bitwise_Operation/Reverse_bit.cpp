#include<iostream>
using namespace std;
void f_reverse()
{
    uint32_t num, res=0,store;
    cout<<"Enter the number ";
    cin>>num;
    store= num;
    while(num)
    {
        res<<=1;
        res|=num&1;
        num>>=1;

    }
     cout<<res<<" Actual data "<<store<<endl;
    return;
}
int main()
{   
   
 f_reverse();
    return 0;
}