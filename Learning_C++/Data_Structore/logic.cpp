 /*Input “ABC”, “XYZ”, “MNO”, 2, “JKL”, “DFG”, “CVB”, 5
On the input of 2 “XYZ” is expected to be printed.
On the input of 5 “DFG” is expected to be printed.
*/
#include<iostream>
#include <vector>
using namespace std;
int main()
{
string arr[]= {"ABC", "XYZ","MNO","2","JKL", "DFG", "CVB", "5"};
vector<string> sres;
vector<int > ires;
int size = sizeof(arr)/sizeof(arr[0]);
for(int i = 0;i<size;i++)
{
    if(isdigit(arr[i][0]))
    {
        ires.push_back(stoi(arr[i]));
    }
    else 
    {
        sres.push_back(arr[i]);
    }
}
for (auto res: ires)
{
    cout<<sres[res];
}
return 0;
}