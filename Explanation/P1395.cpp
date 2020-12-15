#include<bits/stdc++.h>
using namespace std;
const int N=50500;
vector<int> a[50020];
int s[50020];
int f[50020];
int n;
void dfs(int x,int fa)
{
	s[x]=1;
	for(int i=0;i<a[x].size();i++)
	{
		if(a[x][i]!=fa)
		{
			dfs(a[x][i],x);
			s[x]+=s[a[x][i]];
			f[x]+=f[a[x][i]]+s[a[x][i]];
		}
	}
}
void solve(int x,int y)
{
	for(int i=0;i<a[x].size();i++)
	{
		if(a[x][i]!=y)
		{
			f[a[x][i]]+=f[x]-(f[a[x][i]]+s[a[x][i]])+(n-s[a[x][i]]);
			solve(a[x][i],x);
		}
	}
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<n;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		a[y].push_back(x);
		a[x].push_back(y);
	}
	dfs(1,0);
	solve(1,0);
	int ans=1;
	for(int i=1;i<=n;i++)
	{
		if(f[ans]>f[i])
		{
			ans=i;
		}
	}
	printf("%d %d",ans,f[ans]);
	return 0;
}
