#include<bits/stdc++.h>
using namespace std;
const int N=1500,M=50005;
int head[N],ver[M],edge[M],d[N],in[N],cnt,nxt[M];
void add(int x,int y,int z)
{
	ver[++cnt]=y;
	edge[cnt]=z;
	nxt[cnt]=head[x];
	head[x]=cnt;
}
int n,m;
int v[N];
queue<int> q;
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		add(x,y,z);
		in[y]++;
	}
	for(int i=2;i<=n;i++)
	{
		d[i]=-100000;
		if(in[i]==0)
		{
			for(int j=head[i];j;j=nxt[j])
			{
				in[ver[j]]--;
			}
		}
	}
	q.push(1);
	d[1]=0;
	while(q.size())
	{
		int x=q.front();
		q.pop();
		for(int i=head[x];i;i=nxt[i])
		{
			v[ver[i]]=1;
			d[ver[i]]=max(d[ver[i]],d[x]+edge[i]);
			in[ver[i]]--;
			if(in[ver[i]]==0)
			{
				q.push(ver[i]);
			}
		}
	}
	if(!v[n])
	{
		d[n]=-1;
	}
	printf("%d",d[n]);
	return 0;
}
