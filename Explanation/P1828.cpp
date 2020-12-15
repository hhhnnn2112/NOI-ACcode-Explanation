#include<bits/stdc++.h>
using namespace std;
const int N=850;
const int M=3000;
int head[N],edge[M],ver[M],nxt[M];
int cnt;
int n,p,c;
int d[N],a[N],v[N];
void add(int x,int y,int z)
{
	ver[++cnt]=y;
	nxt[cnt]=head[x];
	edge[cnt]=z;
	head[x]=cnt;
}
priority_queue<pair<int,int> > q;
void dij(int st)
{
	memset(d,0x3f,sizeof d);
	memset(v,0,sizeof v);
	while(!q.empty())q.pop();
	d[st]=0;
	q.push(make_pair(-d[st],st));
	while(!q.empty())
	{
		int x=q.top().second;
		q.pop();
		if(v[x])continue;
		v[x]=1;
		for(int i=head[x];i;i=nxt[i])
		{
			int y=ver[i],z=edge[i];
			if(d[x]+z<d[y])
			{
				d[y]=d[x]+z;
				q.push(make_pair(-d[y],y));
			}
		}
	}
}
int ans=0x3f3f3f3f;
int main()
{
	scanf("%d%d%d",&n,&p,&c);
	for(int i=1;i<=n;i++)
	{
		int x;
		scanf("%d",&x);
		a[x]++;
	}
	for(int i=1;i<=c;i++)
	{
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		add(x,y,z);
		add(y,x,z);
	}
	for(int i=1;i<=p;i++)
	{
		dij(i);
		int tmp=0;
		for(int j=1;j<=p;j++)
		{
			tmp+=d[j]*a[j];
		}
		ans=min(ans,tmp);
	}
	printf("%d",ans);
	return 0;
}
