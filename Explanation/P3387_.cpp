#include<bits/stdc++.h>
using namespace std;
const int N=10050,M=100500;
int p[N],dfn[N],low[N],num;
int head[N],nxt[N],ver[N],from[M],cnt;
int head2[N],nxt2[M],ver2[M],from2[M];
int stac[N],top;
int d[N];
int v[N],sd[N];
int tot;
int n,m,in[N];
void add(int  x,int y)
{
	ver[++cnt]=y;
	from[cnt]=x;
	nxt[cnt]=head[x];
	head[x]=cnt;
}
void tarjan(int x)
{
	dfn[x]=low[x]=++num;
	stac[++top]=x;
	v[x]=1;
	for(int i=head[x];i;i=nxt[i])
	{
		int y=ver[i];
		if(!dfn[y])
		{
			tarjan(y);
			low[x]=min(low[x],low[y]);
		}
		else if(v[y])
		{
			low[x]=min(low[x],dfn[y]);
		}
	}
	if(dfn[x]==low[x])
	{
		int y;
		while(y=stac[top--])
		{
			sd[y]=x;
			v[y]=0;
			if(x==y)break;
			p[x]+=p[y];
		}
	}
}
int tupo()
{
	queue<int> q;
	int tot=0;
	for(int i=1;i<=n;i++)
	{
		if(sd[i]==i&&!in[i])
		{
			q.push(i);
			d[i]=p[i];
		}
	}
	while(!q.empty())
	{
		int x=q.front();
		q.pop();
		for(int i=head2[x];i;i=nxt2[i])
		{
			int y=ver2[i];
			d[y]=max(d[y],d[x]+p[y]);
			in[y]--;
			if(in[y]==0)
			{
				q.push(y);
			}
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		ans=max(ans,d[i]);
	}
	return ans;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&p[i]);
	}
	for(int i=1;i<=m;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		add(x,y);
	}
	for(int i=1;i<=n;i++)
	{
		if(!dfn[i])
		{
			tarjan(i);
		}
	}
	for(int i=1;i<=m;i++)
	{
		int x=sd[from[i]],y=sd[ver[i ]];
		if(x!=y)
		{
			nxt2[++cnt]=head2[x];
			ver2[cnt]=y;
			from2[cnt]=x;
			head2[x]=cnt;
			in[y]++;
		}
	}
	printf("%d",tupo());
	return 0;
}
