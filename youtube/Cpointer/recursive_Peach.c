#include <stdio.h>
int getPeachNumber(n)
{
    int num;    //define the numbers of peach
    if(n==10)
    {
       return 1;       //Recursive end condition
    } 
    else
    {
        num = (getPeachNumber(n + 1) + 1)*2;   //Recursive
        printf("the %dth day remain %d peaches\n", n, 2*(n+1)); //days,peaches
    }
    return num;
}
int main()
{
    int num = getPeachNumber(1);
    printf("THe monkey get %d peaches.\n", num);
    return 0;
}
