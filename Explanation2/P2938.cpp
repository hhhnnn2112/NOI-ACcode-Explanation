#include<bits/stdc++.h>
using namespace std;
int s,d,m;
int ans;
int f[505000],a[55][20];
int main()
{
	scanf("%d%d%d",&s,&d,&m);
	for(int i=1;i<=s;i++)
	{
		for(int j=1;j<=d;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	for(int t=1;t<d;t++)
	{
		memset(f,0,sizeof f);
		for(int i=1;i<=s;i++)
		{
			for(int j=a[i][t];j<=m;j++)
			{
				f[j]=max(f[j],f[j-a[i][t]]+a[i][t+1]-a[i][t]);
				ans=max(ans,f[j]);
			}
		}
		m+=ans;
		ans=0;
	}
	printf("%d",m);
	return 0;
} 
