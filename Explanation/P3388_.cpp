#include<bits/stdc++.h>
using namespace std;
const int N=2e4+10;
const int M=2e5+10;
int head[N],ver[M],nxt[M],cnt;
int low[N],dfn[N],tim;
int n,m;
int v[N];

void add(int x,int y)
{
	ver[++cnt]=y;
	nxt[cnt]=head[x];
	head[x]=cnt;
}

void tarjan(int x,int fa)
{
	dfn[x]=low[x]=++tim;
	int child=0;
	for(int i=head[x];i;i=nxt[i])
	{
		int y=ver[i];
		if(!dfn[y])
		{
			tarjan(y,fa);
			low[x]=min(low[x],low[y]);
			if(low[y]>=dfn[x]&&x!=fa)
			{
				v[x]=1;
			}
			if(x==fa)
			{
				child++;
			}
		}
		low[x]=min(low[x],dfn[y]);
	}
	if(child>=2&&x==fa)
	{
		v[x]=1;
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		add(x,y);
		add(y,x);
	}
	for(int i=1;i<=n;i++)
	{
		if(dfn[i]==0)
		{
			tarjan(i,i);
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		if(v[i])
		{
			ans++;
		}
	}
	printf("%d\n",ans);
	for(int i=1;i<=n;i++)
	{
		if(v[i])
		{
			printf("%d ",i);
		}
	}
	return 0;
}
