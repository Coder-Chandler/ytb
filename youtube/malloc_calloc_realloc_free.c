#include <stdio.h>
#include <stdlib.h>
int main()
{
  int n;
  printf ("Enter size of array\n");
  scanf("%d",&n);
  int *A = (int*)malloc(n*sizeof(int));
  
  for(int i=0; i<n; i++)
  {
    A[i] = i+1;
  }
  //int *B = (int*)realloc(A, 2*n*sizeof(int));
  //int *B = (int*)realloc(A, (n/2)*sizeof(int));
  //A = (int*)realloc(NULL, (n/2)*sizeof(int));//equal free(A)
  int *B = (int*)realloc(A,0);//equal free(A)
  //int *B = (int*)realloc(NULL, n*sizeof(int));//equal to malloc
  printf ("Adress A = %d  Adress B = %d\n",A,B);
  //printf ("Address A = %d\n",A);
  //free(A);
  //A[2] = 66;
  //A = NULL;//It is a good practice to set pointer address as NULL after call to free. NULL is a macro for address 0 is and it cannot be dereferenced. The code below this statement will now cause a crash.
  //for(int i=0; i<2*n; i++)
  for(int i=0; i<n; i++)
  {
    //printf ("%d\n", B[i]);
    printf ("%d\n", A[i]);
  }
  printf ("\n");
  for(int i=0; i<n; i++)
  {
    printf ("%d\n", B[i]);
    //printf ("%d\n", A[i]);
  }
  printf ("\n");
}
