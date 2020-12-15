#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
int n,m;
int z=1;
int f[100050];
int d[100050],c[100050];
int find(int k)
{
	if(f[k]==k)
	{
		return k;
	}
	return f[k]=find(f[k]);
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		f[i]=i;
		c[i]=1;
	}
	for(int i=1;i<=m;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		x=find(x);
		y=find(y);
		d[x]++;
		if(x!=y)
		{
			f[y]=x;
			c[x]+=c[y];
			d[x]+=d[y];
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(f[i]==i)
		{
			if(c[i]>d[i])
			{
				z=(long long)z*c[i]%mod;
			}
			else if(c[i]==d[i])
			{
				z=z*2%mod;
			}
			else
			{
				z=0;
			}
		}
	}
	printf("%d",z);
	return 0;
}
