#include <stdio.h>
#include <stdlib.h>
int Add (int *a,int *b)
{
    printf ("addess of a in Add  = %d\n",&a);
    printf ("Vallue in a of Add(address of a of main) = %d\n",a);
    printf ("Value at address stored in a of Add = %d\n",*a);
    int c = (*a) + (*b);
    printf ("value c in Add pointer = %d\n",*c);
    printf ("address of c in Add = %d\n",&c);
}
int main()
{
    int a = 2,b = 4;
    printf ("address of a in main = %d\n",&a);
    int c = Add(&a,&b);
    printf("address of c in main = %d\n",&c);
    printf ("Sum = %d\n",c);
    
}
