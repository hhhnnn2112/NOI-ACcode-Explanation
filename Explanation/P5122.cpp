#include<bits/stdc++.h>
using namespace std;
const int N=50040,M=200005;
int cnt,head[N],edge[M],nxt[M],ver[M];
void add(int x,int y,int z)
{
	ver[++cnt]=y;
	edge[cnt]=z;
	nxt[cnt]=head[x];
	head[x]=cnt;
}
int n,m,k;
int d1[50020],d2[50020];
set<pair<int,int > > s; 
void dij(int d[])
{
	for(int i=1;i<=n;i++)
	{
		s.insert(make_pair(d[i],i));
	}
	while(s.size())
	{
		int x=s.begin() -> second;
		s.erase(s.begin());
		for(int i=head[x];i;i=nxt[i])
		{
			if(d[ver[i]]>d[x]+edge[i])
			{
				s.erase(make_pair(d[ver[i]],ver[i]));
				d[ver[i]]=d[x]+edge[i];
				s.insert(make_pair(d[ver[i]],ver[i]));
			}
		}
	}
}
int main()
{
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++)
	{
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		add(x,y,z);
		add(y,x,z);
	}
	memset(d1,0x3f,sizeof d1);
	d1[n]=0;
	dij(d1);
	memset(d2,0x3f,sizeof d2);
	for(int i=0;i<k;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		d2[x]=d1[x]-y;
	}
	dij(d2);//d2 是必须走一个干草堆 
	for(int i=1;i<n;i++)
	{
		printf("%d\n",d1[i]>=d2[i]);
	}
	return 0;
}
