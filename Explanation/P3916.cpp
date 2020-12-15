#include<bits/stdc++.h>
using namespace std;
const int N=100006;
int cnt,head[N],ver[N],nxt[N];
void add(int x,int y)
{
	ver[++cnt]=y;
	nxt[cnt]=head[x];
	head[x]=cnt;
}
int a[N];
int n,m;
void dfs(int x,int r)
{
	if(a[x])return;
	a[x]=r;
	for(int i=head[x];i;i=nxt[i])
	{
		dfs(ver[i],r);
	}
}
int main ()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		int x,y;
		cin>>x>>y;
		add(y,x);
	}
	for(int i=n;i>=1;i--)
	{
		dfs(i,i);
	}
	for(int i=1;i<=n;i++)
	{
		cout<<a[i]<<" ";
	}
	return 0;
}
