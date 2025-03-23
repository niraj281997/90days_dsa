#include<stdio.h>
#include<math.h>
int main()
{
    const int a = 10;
    int * ptr = (int*)&a;
    *ptr =20;
    printf("*ptr = %d",*ptr);
    printf(" a = %d",a);
    int digit = log10(3) +1;
    printf(" %ld",digit);
    return 0;
}