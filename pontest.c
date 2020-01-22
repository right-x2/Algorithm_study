#include <stdio.h>
#include <stdlib.h>

int main ()
{
	int data[100];
	int* p1;
	for (int i = 0; i <100;i++) { data[i] = i; }
	p1 = data; //Assigning base address of an array to pointer
	for (int i = 0; i <100;i++) //Accessing Array using index
	{
		printf ("\n%d",p1[i]); 
	}
	for (int i = 0; i <100;i++) //Access Array using Pointer Arithmetic
	{
		printf ("\n%d",*(p1 +i));
	}
	return 0;
}
