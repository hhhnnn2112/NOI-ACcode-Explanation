#include<bits/stdc++.h>
using namespace std;
int cnt;
const int N=100050;
const int M=500050;
int head[N],from[M],nxt[M],ver[M],edge[M];
void add(int x,int y,int z)
{
	ver[++cnt]=y;
	from[cnt]=x;
	edge[cnt]=z;
	nxt[cnt]=head[x];
	head[x]=cnt;
}
int d[N];
int f[N],c[N];
int n,m,t;
vector<int > q;
set<pair<int ,int > >s;
void dij()
{
	memset(d,0x3f,sizeof d);
	d[1]=0;
	s.insert(make_pair(0,1));
	while(s.size())
	{
		int x=s.begin() -> second;
		q.push_back(x);
		s.erase(s.begin());
		for(int i=head[x];i;i=nxt[i])
		{
			int y=ver[i];
			int z=edge[i];
			if(d[y]>d[x]+z)
			{
				s.erase(make_pair(d[y],y));
				d[y]=d[x]+z;
				f[y]=x;
				s.insert(make_pair(d[y],y));
			}
			else if(d[y]==d[x]+z)
			{
				f[y]=min(f[y],x);
			}
		}
	}
}
int main()
{
	scanf("%d%d%d",&n,&m,&t);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&c[i]);
	}
	for(int i=1;i<=m;i++)
	{
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		add(x,y,z);
		add(y,x,z);
	}
	dij();
	long long ans=0;
	for(int i=q.size()-1;i>0;i--)
	{
		ans=max(ans,(long long )c[q[i]]*(d[q[i]]-t));
		c[f[q[i]]]+=c[q[i]];
	}
	printf("%lld",ans);
	return 0;
}
