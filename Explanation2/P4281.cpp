#include<bits/stdc++.h>
using namespace std;
const int N=1000050;
int head[N],ver[N],nxt[N],cnt,f[N][20],d[N],c[N];
void add(int x,int y)
{
	ver[++cnt]=y;
	nxt[cnt]=head[x];
	head[x]=cnt;
}
int n,m;
void dfs(int x,int fa)
{
	d[x]=d[fa]+1;
	f[x][0]=fa;
	for(int i=1;i<=19;i++)
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
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<n;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		add(x,y);
		add(y,x);
	}
	dfs(1,0);
	for(int i=1;i<=m;i++)
	{
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		int t,tt,ttt;
		t=lca(a,b);
		tt=lca(b,c);
		ttt=lca(a,c);
		printf("%d %d\n",t^tt^ttt,d[a]+d[b]+d[c]-d[t]-d[tt]-d[ttt]);
	}
	return 0;
}
