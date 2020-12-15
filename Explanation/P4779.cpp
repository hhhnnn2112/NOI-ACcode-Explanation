#include<bits/stdc++.h>
using namespace std;
const int N=10000+10;
const int M=500000+10;
int d[N],v[N];
int cnt,head[N],ver[M],nxt[M],edge[M];
void add(int x,int y,int z)
{
	ver[++cnt]=y;
	nxt[cnt]=head[x];
	head[x]=cnt;
	edge[cnt]=z;
}
int n,m,s;
void dij(int s)
{
	memset(d,0x3f,sizeof d);
	priority_queue<pair<int,int > > q;
	q.push(make_pair(0,s));
	d[s]=0;
	while(!q.empty())
	{
		int x=q.top().second;
		q.pop();
		if(v[x])continue;
		v[x]=1;
		for(int i=head[x];i;i=nxt[i])
		{
			int y=ver[i];
			int z=edge[i];
			if(d[x]+z<d[y])
			{
				d[y]=d[x]+z;
				q.push(make_pair(-d[y],y));
			}
		}
	}
}
int main()
{
	scanf("%d%d",&n,&m,&s);
	for(int i=1;i<=m;i++)
	{
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		add(x,y,z);
	}
	dij(s);
	for(int i=1;i<=n;i++)
	{
		printf("%d ",d[i]);
	}
	return 0;
}
