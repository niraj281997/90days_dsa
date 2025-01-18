#include<iostream>
using namespace std;

/* 
  number = 0b1100;         // 12 in decimal
  mask = 0b0010;           // 2 in decimal
  Set_Reset = 1;           // 1 in decimal
  position = 1;            // Targeting the second bit

 (Set_Reset << position) & mask;
  Set_Reset = 1; // position = 1; 
  Set_Reset << position = 0b10; 
  1 shifted left by 1 position 
  mask = 0b0010; 
  Result = 0b10 & 0b0010 = 0b10;
  Result after masking

 number & ~mask | ((Set_Reset << position) & mask);
 number & ~mask = 0b1100;
 ((Set_Reset << position) & mask) = 0b10;
 Result = 0b1100 | 0b10 = 0b1110; // Final result after setting the bit


 number & ~mask | ((Set_Reset << position) & mask);
 number & ~mask = 0b1100;
 ((Set_Reset << position) & mask) = 0b10;
 Result = 0b1100 | 0b10 = 0b1110; // Final result after setting the bit

 */
int Function(int number,int position, int Set_Reset)
{
    int mask = 1<<position;
    number = number&~mask | ((Set_Reset<<position) &mask);
    return 0;
}
int main()
{
    return 0;
}