/*
Name: Katuku Muthami 
Reg : CT100/G/26212/25
2D array
*/
#include<stdio.h>

int main()
{
int scores [2] [2] ={
    {65, 92},
    {84, 72}
};
   //printing array using nested loop
   for (int i=0 ; i<2 ; i++)
   {
   for (int k = 0; k<2; k++)
   {
    printf("%d", scores [i][k]);
    }
    printf("\n");
    //move to next row
    }
    return 0;
}