#include <stdio.h>
int compare (int a,int b)
{
    printf ("address compare in compare = %d\n",&compare);//134513693

    if (a > b) return -1;
    return 1;
}
void BubbleSort (int A[],int n, int (*compare)(int, int))
{
    int i, j, temp;
    printf ("address i j temp in BubbleSort = %d %d %d\n",i,j,temp);//134514504 -1081198684 -1218952176

    printf ("address copare in BUbbleSort = %d\n",compare);//134513693
    printf ("address A in bubblesort = %d\n",A);//-1081198664

    for (i = 0; i < n; i++)
        for (j = 0;j < i; j++)
        {
            if (compare(A[j], A[j+1]) > 0)
            {
                 temp =A[i];                                                
                 A[i] = A[j];
                 A[j] = temp;
            }
        }
}
int main()
{
    int i, A[] = {2,4,3,7,5,6};
    
    
    BubbleSort(A, 6, compare);
    printf ("adress compare in main = %d\n",&compare);//134513693

    printf ("address i in main = %d\n",i);//-1081198476

    printf ("address A in main = %d\n",A);//-1081198664
    for (i = 0; i < 6; i++) printf ("%d\n",A[i]);
}
