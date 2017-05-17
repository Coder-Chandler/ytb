#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int compare (const void *a, const void *b)
{
    int A = *((int*)a);
    int B = *((int*)b);
    return abs(A) - abs(B);
}
int main()
{
    int i, A[] = {-31,22,-1,50,-6,4};
    qsort(A,6,sizeof(int),compare);
    for (i = 0; i<6; i++) printf ("%d\n", A[i])
}
/*qsort 的函数原型是void __cdecl qsort ( void *base, size_t num, size_t width, int (__cdecl *comp)(const void *, const void* ) ) 
其中base是排序的一个集合数组，num是这个数组元素的个数，width是一个元素的大小，comp是一个比较函数。
*/
