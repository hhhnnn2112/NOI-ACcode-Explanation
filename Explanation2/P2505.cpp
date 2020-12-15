#include<bits/stdc++.h>
using namespace std;
int cnt;
int n,m;
const int N=5*1e4;
const int M=1e5;
const int mod=1000000007;
int head[N],nxt[M],ver[M],edge[M];
int d[N],f[N],g[N],ans[N];
vector <int > b;
void add(int x,int y,int z)
{
	ver[++cnt]=y;
	edge[cnt]=z;
	nxt[cnt]=head[x];
	head[x]=cnt;
}
priority_queue<pair <int ,int > > q;
int v[N];
void dij(int s)
{
	memset(v,0,sizeof v);
	memset(d,0x3f,sizeof d);
	memset(f,0,sizeof f);
	b.clear();
	while(!q.empty())
	{
		q.pop();
	}
	d[s]=0;
	f[s]=1;
	q.push(make_pair(0,s));
	while(!q.empty())
	{
		int x=q.top().second;
		q.pop();
		if(v[x])continue;
		v[x]=1;
		b.push_back(x);
		for(int i=head[x];i;i=nxt[i])
		{
			int y=ver[i];
			int z=edge[i];
			if(d[y]>d[x]+z)
			{
				d[y]=d[x]+z;
				f[y]=f[x];
				q.push(make_pair(-d[y],y));
			}
			else if(d[y]==d[x]+z)
			{
				f[y]=(f[x]+f[y])%mod;
			}
		}
	}
	for(int i=b.size()-1;i>=0;i--)
	{
		g[b[i]]=1;
		int x=b[i];
		for(int i=head[x];i;i=nxt[i])
		{
			int y=ver[i];
			int z=edge[i];
			if(d[y]==d[x]+z)
			{
				g[x]=(g[x]+g[y])%mod;
				ans[i]=(ans[i]+(long long)f[x]*g[y])%mod;
			}
		}
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		add(x,y,z);
	}
	for(int i=1;i<=n;i++)
	{
		dij(i);
	}
	for(int i=1;i<=m;i++)
	{
		printf("%lld\n",ans[i]);
	}
	return 0;
}
