#include"temp.h"

int main()
{
 	int array[] = {1,2,3,4,1,2,3,4,11,22,33,44,1,2};
	map< int, int> mp;
	for(int i= 0;i<sizeof(array)/sizeof(int);i++)
	{
		if(mp[array[i]]==1)
		{
			cout<<"element"<<array[i]<<endl;
			exit(0);
		}
		cout<<mp[array[i]]++<<endl;
	}
	cout<<"No repeating element "<<endl;
	return 0;

}
