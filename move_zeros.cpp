#include"temp.h"

int main()
{
int array[] = {1,2,3,4,0,1,2,3,4,0,1,2,3,4};
int n = sizeof(array)/sizeof(int);
int left = 0;
for (int i = 0 ; i<n ; i++)
	if(array[i] !=0)
	{
	std::swap(array[i],array[left++]);
	}

for(int i = 0;i<sizeof(array)/sizeof(int);i++)
		cout<<" "<<array[i];
	cout<<endl;
return 0;
}

