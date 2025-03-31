/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include<iostream>
#include<string>
#include <algorithm>
using namespace std;
/* 
intput : " Hello! From Mac !!"
output : "olleH ! morF caM !!"
 */
int main()
{
    string s = " Hello! From Mac !!";
    string res;
    string local="";
    for(auto ch : s )
    {
        if(
            (ch >='A' && ch <='Z')||
            (ch >='a' && ch <='z'))
        local +=ch;
        else 
        {
            if(!local.empty())
            {
                reverse(local.begin(), local.end());
                res+=local;
                local="";
            }
            res += ch;
            
        }
    }
    if (!local.empty())
    {
        reverse(local.begin(), local.end());
        res += local;
    }
    cout<<s<<endl<<res<<endl;

    return 0;
}