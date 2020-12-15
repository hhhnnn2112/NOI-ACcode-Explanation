#include<bits/stdc++.h>
using namespace std;
int a[10];
int sum=50;
int main()
{
	for(int i=1;i<=9;i++)
	{
		scanf("%d",&a[i]);
		if(i==8)
		{
			if(a[i])
			{
				sum+=4;
			}
		}
		if(i==9)
		{
			if(sum>=a[i])
			{
				printf("AKIOI");
			}
			else
			{
				printf("AFO");
			}
		}
		sum+=a[i];
	}
	return 0;
}
