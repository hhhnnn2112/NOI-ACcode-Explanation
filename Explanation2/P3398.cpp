#include<bits/stdc++.h>
using namespace std;
const int N=200100;
int head[N],ver[N],nxt[N],f[N][20];
int cnt;
int d[N];
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
	for(int i=1;i<=19;i++)
	{
		f[x][i]=f[f[x][i-1]][i-1];
	}
	for(int i=head[x];i;i=nxt[i])
	{
		if(ver[i]==fa)
		{
			continue;
		}
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
	for(int i=0;i<=19;i++)
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
int n,q;
int dis(int x,int y)
{
	int c=lca(x,y);
	return abs(d[c]-d[x])+abs(d[c]-d[y]);
}
int main()
{
	scanf("%d%d",&n,&q);
	for(int i=1;i<n;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		add(x,y);
		add(y,x);
	}
	dfs(1,0);
	for(int i=1;i<=q;i++)
	{
		int xx,yy,x,y;
		scanf("%d%d%d%d",&x,&y,&xx,&yy);
		int la=lca(x,y);
		int lb=lca(xx,yy);
		if(dis(x,lb)+dis(y,lb)==dis(x,y)||dis(xx,la)+dis(yy,la)==dis(xx,yy))
		{
			puts("Y");
		}
		else
		{
			puts("N");
		}
	}
	return 0;
}
