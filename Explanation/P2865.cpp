#include<bits/stdc++.h>
using namespace std;
const int N=5005,M=200005;
int cnt;
int head[N],nxt[M],ver[M],edge[M];
void add(int x,int y,int z)
{
	ver[++cnt]=y;
	edge[cnt]=z;
	nxt[cnt]=head[x];
	head[x]=cnt;
}
priority_queue<pair<int ,int > > q1,q2;
int ans=0x3f3f3f3f;
int da[N],db[N],v[N];
int n,m;
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		add(x,y,z);
		add(y,x,z);
	}
	
	memset(v,0,sizeof v);
	memset(da,0x3f,sizeof da);
	da[1]=0;
	q1.push(make_pair(0,1));
	while(!q1.empty())
	{
		int x=q1.top().second;
		q1.pop();
		if(v[x])continue;
		v[x]=1;
		for(int i=head[x];i;i=nxt[i])
		{
			int y=ver[i];
			int z=edge[i];
			if(da[x]+z<da[y])
			{
				da[y]=da[x]+z;
				q1.push(make_pair(-da[y],y));
			}
		}
	}	
	memset(v,0,sizeof v);
	memset(db,0x3f,sizeof db);
	db[n]=0;
	q2.push(make_pair(0,n));
	while(!q2.empty())
	{
		int x=q2.top().second;
		q2.pop();
		if(v[x])continue;
		v[x]=1;
		for(int i=head[x];i;i=nxt[i])
		{
			int y=ver[i];
			int z=edge[i];
			if(db[x]+z<db[y])
			{
				db[y]=db[x]+z;
				q2.push(make_pair(-db[y],y));
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=head[i];j;j=nxt[j])
		{
			if(da[i]+db[ver[j]]+edge[j]>db[1])
			{
				ans=min(ans,da[i]+db[ver[j]]+edge[j]);
			}
		}
	}
	printf("%d",ans);
	return 0;
}
