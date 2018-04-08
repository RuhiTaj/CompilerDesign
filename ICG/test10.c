#include <stdio.h>
int main()
{
	int ab=3;
	int a[10];
	int x=a[ab-2];
	int i=0;

	for(i=0;i<=10;i=i+1)
	{
	a[i]=a[i]+6;
	}
	return 0;
}
