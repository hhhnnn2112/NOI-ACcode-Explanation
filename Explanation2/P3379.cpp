#include<bits/stdc++.h>
using namespace std;
const int N=1000010;
int head[N],ver[N],nxt[N],cnt,f[N][20],d[N];
void add(int x,int y)
{
	ver[++cnt]=y;
	nxt[cnt]=head[x];
	head[x]=cnt;
}
void dfs(int x,int fa)
{
	f[x][0]=fa;
	d[x]=d[fa]+1;
	for(int i=1;i<20;i++)
	{
		f[x][i]=f[f[x][i-1]][i-1];
	}
	for(int i=head[x];i;i=nxt[i])
	{
		if(ver[i]==fa)continue;
		dfs(ver[i],x);
	}
}
int lca(int x,int y)
{
	if(d[x]<d[y])
	{
		swap(x,y);
	}
	int dd=d[x]-d[y];
	for(int i=0;i<20;i++)
	{
		if(dd>>i&1)
		{
			x=f[x][i];
		}
	}
	if(x==y)
	{
		return x;
	}
	for(int i=19;i>=0;i--)
	{
		if(f[x][i]!=f[y][i])
		{
			x=f[x][i];
			y=f[y][i];
		}
	}
	return f[x][0];
}
int n,m,s;
int main()
{
	scanf("%d%d%d",&n,&m,&s);
	for(int i=1;i<n;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		add(x,y);
		add(y,x);
	}
	dfs(s,0);
	for(int i=1;i<=m;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		printf("%d\n",lca(x,y));
	}
	return 0;
}
