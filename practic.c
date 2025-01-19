#include<stdio.h>
#include<string.h>
char* func()
{
char name[] = “name”;
return name;
}


int main(){


char* ptr = func();


printf(“%s”,&ptr);


}