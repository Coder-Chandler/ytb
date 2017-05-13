#include <stdio.h>
/*
int main()
{
  char C[20];
  C[0] = 'J';
  C[1] = 'O';
  C[2] = 'H';
  C[3] = 'N';
  printf ("%s\n",C);//JOHN��W��3o�(garbage value!!)
  int len = strlen(C);
  printf ("length = %d\n",len);
  //Not equal to 4 ,it's 12(because the garbage value) 
}

int main()
{
  char c[20];
  c[0] = 'j';
  c[1] = 'o';
  c[2] = 'h';
  c[3] = 'n';
  c[4] = '\0';//add this line,then will be ok !
  printf ("%s\n",c);
  int length = strlen(c);
  printf ("length = %d\n",length);
}
*/
int main()
{
  char C1[6] = "HELLO";
  char *C2;
  C2 = C1;//it is valid!and it's the same as C2 = &C1
  printf ("C2[1] is %c\n",C2[1]);//you must write %c instead of %s ! %s in here will cause a Segmentation fault !
}
