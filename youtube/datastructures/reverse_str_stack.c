//string reversal using stack
//#include <iostream>
//#include <stdlib.h>
#include <stdio.h>
#include <stack>
#include <cstring>
using namespace std;
class Stack
{
	private:
		char A[101];
		int top;
	public:
		void Push(int x);
		void Pop();
		void Top();
		bool IsEmpty();
};
void Reverse(char *C,int n)
{
	stack <char> S;
	//loop for push
	for (int i = 0; i<n; i++)
	{
		S.push(C[i]);
	}
	//loop for pop
	for (int j = 0; j<n; j++)
	{
		C[j] = S.top();//overwrite the character at index i
		S.pop();
	}
}
int main()
{
	char C[51];
	printf ("Enter a string : ");
	gets(C);
	Reverse(C,strlen(C));
	printf ("Output = %s",C);
	printf ("\n");
}


