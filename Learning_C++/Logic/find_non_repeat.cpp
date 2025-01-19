#include"temp.h"
/*
find non repeat element
Summery 
 */
int main()
{
	int array[] = {1,2,3,4,1,2,4,3,7,7,8};
	int local = 0;
	for(int i=0 ; i<sizeof(array)/sizeof(int);i++)
	{
	 local^=array[i]; 
	}
	cout<<endl<<"size of array "<<sizeof(array)/sizeof(int)<<endl;
	cout<<"Non repeating element "<<local<<endl;
	return 0;
}
