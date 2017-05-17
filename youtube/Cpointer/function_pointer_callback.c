#include <stdio.h>
void A()
{
    printf ("hello\n");
    printf ("address A = %d\n",&A);//693
}
void B(void(*ptr)())
{
    ptr();
    printf ("address ptr in B = %d\n",ptr);//693
    printf ("adress B = %d\n",&B);//733
}
int main()
{
    void(*p)() = A;
    printf ("address p in main = %d\n",p);//693
    B(p);
    printf ("adress B in main = %d\n",B);//733

}
