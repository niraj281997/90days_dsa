#include<iostream>
using namespace std;

int main()
{
/* 
Input: word1 = "abc", word2 = "pqr"
Output: "apbqcr"

Input: word1 = "ab", word2 = "pqrs"
Output: "apbqrs"
 */

string word1 = "abc";
string word2 = "pqr";  
string result = "";
int i = 0;
for ( i = 0;(i < sizeof(word1) && i < sizeof(word2)); i++)
{
    result += word1[i];
    result += word2[i];
}
if ( i < sizeof(word1))
{
    result += word1.substr(i);
}
if ( i < sizeof(word2))
{
    result += word2.substr(i);

}
cout<<result<<endl;
return 0;
}