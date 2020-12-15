#include<bits/stdc++.h>
using namespace std;
const int N=1060,M=10050;
int head[N],ver[M],d[N],cnt,nxt[M];
void add(int x,int y)
{
	ver[++cnt]=y;
	nxt[cnt]=head[x];
	head[x]=cnt;
}
int ans=0;
int n,m,k;
int v[N];
void dfs(int x)
{
	d[x]++;
	v[x]=1;
	for(int i=head[x];i;i=nxt[i])
	{
		if(v[ver[i]])continue;
		dfs(ver[i]);
	}
}
int a[N];
int main()
{
	scanf("%d%d%d",&k,&n,&m);
	for(int i=1;i<=k;i++)
	{
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=m;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		add(x,y);
	}
	for(int i=1;i<=k;i++)
	{
		memset(v,0,sizeof v);
		dfs(a[i]);
	}
	for(int i=1;i<=n;i++)
	{
		if(d[i]==k)
		{
			ans++;
		}
	}
	printf("%d",ans);
	return 0;
}
