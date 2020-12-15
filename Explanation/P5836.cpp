#include<bits/stdc++.h>
using namespace std;
const int N=200050;
int head[N],ver[N],nxt[N],cnt,f[N][20],d[N],c[N];
void add(int x,int y)
{
	ver[++cnt]=y;
	nxt[cnt]=head[x];
	head[x]=cnt;
}
char s[N];
int n,m;
void dfs(int x,int fa)
{
	f[x][0]=fa;
	d[x]=d[fa]+1;
	c[x]=c[fa]+(s[x]=='H');
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
int main()
{
	scanf("%d%d",&n,&m);
	scanf("%s",s+1);
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
		int x,y;
		char o;
		scanf("%d%d",&x,&y);
		//getchar();
		scanf(" %c",&o);
		int l=lca(x,y);
		int ta=d[x]+d[y]-2*d[l]+1;
		int tb=c[x]+c[y]-2*c[l]+(s[l]=='H');
		if(o=='H')
		{
			printf("%d",tb>0);
		}
		else
		{
			printf("%d",tb<ta);
		}
	}
	return 0; 
}
