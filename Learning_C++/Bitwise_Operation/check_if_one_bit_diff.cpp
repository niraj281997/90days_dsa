#include<iostream>
using namespace std;

bool check(int n1, int n2)
{
    int res = n1^n2;
    return ((res&(res-1))==0);
}

int main()
{
    cout<<check(5,7)<<endl;
    cout<<check(8,6)<<endl;
    return 0;

}