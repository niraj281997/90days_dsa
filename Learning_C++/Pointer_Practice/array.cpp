
#include<stdlib.h>
#include<iostream>
using namespace std;
int main()
{
 int **arr,row,col;
 cout<<"Enter row : ";
 cin>>row;
 cout<<"Enter column : ";
 cin>>col;
 arr= (int**)calloc(row,sizeof(int*));
 for(int i = 0;i<row;i++)
 {
    arr[i] = (int *)calloc(col,sizeof(int));
 }
 for(int i = 0;i<row;i++)
 {
    for(int j = 0;j<col;j++)
    {  
     cin>>arr[i][j];
    }
 }

  for(int i = 0;i<row;i++)
 {
    for(int j = 0;j<col;j++)
    {  
     cout<<arr[i][j]<<" ";
    }
    cout<<endl;
 }

    
    return 0;
}