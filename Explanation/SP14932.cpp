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
int n;
int T,q;
int main()
{
	scanf("%d",&T);
	for(int j=1;j<=T;j++)
	{
		memset(head,0,sizeof head);
		memset(f,0,sizeof f);
		cnt=0;
		printf("Case %d:\n",j);
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			int m;
			scanf("%d",&m);
			for(int k=1;k<=m;k++)
			{
				int x;
				scanf("%d",&x);
				add(x,i);
				add(i,x);
			}
		}
		dfs(1,0);
		scanf("%d",&q);
		for(int i=1;i<=q;i++)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			printf("%d\n",lca(x,y));
		}
	}
	return 0;
}
