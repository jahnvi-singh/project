#include<stdio.h>
int main()
{
	int a;
	printf("enter number:");
	scanf("%d", &a);
	if(a>0)
	{
		printf("%d is positive number",a);
	}
	if(a<0)
	{
		printf("%d is negative number",a);
	}
	if(a==0)
	{
		printf("%d is zero",a);
	}
	return 0;
}
