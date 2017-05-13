#include <stdio.h>
int main()
{
  int A[] = {2,4,5,8,1};
  printf ("%d\n",A);
  printf ("%d\n",&A[0]);
  printf ("%d\n",A[0]);
  printf ("%d\n",*A);
  printf ("%d\n",sizeof(A)-sizeof(A[0]));
  printf ("%d\n",sizeof(A)/sizeof(A[0]));
  printf ("%d\n",sizeof(A));
  printf ("%d\n",sizeof(A[0]));
  int i;
  int *p = A;
  for (i = 0; i < 5; i++)
    {
      printf ("Address = %d\n", &A[i]);
      printf ("Address = %d\n", A + i);
      printf ("Value = %d\n", A[i]);
      printf ("Value = %d\n", *(A+i));
    }
}
//Address:https://www.youtube.com/watch?v=ASVB8KAFypk&list=PL2_aWCzGMAwLZp6LMUKI3cc7pgGsasm2_&index=6
