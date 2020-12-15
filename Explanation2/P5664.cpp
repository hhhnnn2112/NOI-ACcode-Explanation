#include<bits/stdc++.h>
using namespace std;
int n,m;
int ans=0;
const int mod=998244353;
int a[405][2050]; 
int v[4005];
void dfs(int x,int y)//
{
	if(x==n)
	{
		int s=0;
		for(int i=0;i<m;i++)
		{
			s+=v[i];
		}
		for(int i=0;i<m;i++)
		{
			if(v[i]*2>s)
			{
				return;
			}
		}
		ans=(ans+y)%mod; 
		return;
	}
	for(int i=0;i<=m;i++)
	{
		v[i]++;
		dfs(x+1,y*a[x][i]);
		v[i]--;
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	dfs(0,1);
	printf("%d",(ans+mod-1)%mod);
	return 0;
}
