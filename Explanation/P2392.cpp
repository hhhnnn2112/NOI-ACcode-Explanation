#include<bits/stdc++.h>
using namespace std;
int a[5],b[22],f[3000];
int t;
int main()
{
	for(int i=1;i<=4;i++)
	{
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=4;i++)
	{
		memset(b,0,sizeof b);
		memset(f,0,sizeof f);
		int sum=0;
		for(int j=1;j<=a[i];j++)
		{
			scanf("%d",&b[j]);
			sum+=b[j];
		}
		for(int j=1;j<=a[i];j++)
		{
			for(int k=sum/2;k>=b[j];k--)
			{
				f[k]=max(f[k],f[k-b[j]]+b[j]);
			}
		}
		t+=sum-f[sum/2];
	}
	printf("%d",t);
	return 0;
}
