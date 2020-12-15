#include<bits/stdc++.h>
using namespace std;
const int N=10000+10;
const int M=500000+10;
int d[N];
int cnt,head[N],ver[M],nxt[M],edge[M];
void add(int x,int y,int z)
{
	ver[++cnt]=y;
	nxt[cnt]=head[x];
	head[x]=cnt;
	edge[cnt]=z;
}
bool v[N];
void spfa(int s)
{
	queue<int>q;
	v[s]=1;
	d[s]=0;
	q.push(s);
	while(!q.empty())
	{
		int x=q.front();
		v[x]=0;
		q.pop();
		for(int i=head[x];i;i=nxt[i])
		{
			int y=ver[i];
			int z=edge[i];
			if(d[x]+z<d[y])
			{
				d[y]=d[x]+z;
				if(!v[y])
				{
					v[y]=1;
					q.push(y);
				}
			}
		}
	}
}
int n,m,s;
int main()
{
	scanf("%d%d%d",&n,&m,&s);
	for(int i=1;i<=m;i++)
	{
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		add(x,y,z);
	}
	for(int i=1;i<=n;i++)
	{
		d[i]=2147483647;
	}
	spfa(s);
	for(int i=1;i<=n;i++)
	{
		printf("%d ",d[i]);
	}
	return 0;
}
