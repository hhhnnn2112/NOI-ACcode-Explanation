#include<bits/stdc++.h>
using namespace std;
int a[400050],b[400050];
struct edge
{
	int ver,nxt;
}z[400050],f[400050];
int head1[400050],head2[400050],cnt;
void add1(int x,int y)
{
	cnt++;
	z[cnt]=(edge){y,head1[x]};
	head1[x]=cnt;
}
void add2(int x,int y)
{
	cnt++;
	f[cnt]=(edge){y,head2[x]};
	head2[x]=cnt;
}
int n,m;
int s,t;
void dfs(int x,int fa)
{
	a[x]=1;
	for(int i=head2[x];i;i=f[i].nxt)
	{
		int y=f[i].ver;
		if(!a[y])
		{
			dfs(y,x);
		}
	}
}
int d[100050];
void bfs(int st)
{
	if(!b[st])
	{
		printf("-1");
		exit(0);
	}
	queue<int> q;
	q.push(st);
	d[st]=1;
	while(!q.empty())
	{
		int x=q.front();
		q.pop();
		for(int i=head1[x];i;i=z[i].nxt)
		{
			int y=z[i].ver;
			if(b[y]&&!d[y])
			{
				d[y]=d[x]+1;
				q.push(y);
			}
		}
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		if(a==b)continue;
		add1(x,y);
		add2(y,x);
	}
	scanf("%d%d",&s,&t);
	dfs(t,0);
	for(int i=1;i<=n;i++)
	{
		if(!a[i])continue;
		b[i]=1;
		for(int j=head1[i];j;j=z[j].nxt)
		{
			int y=z[j].ver;
			if(!a[y])
			{
				b[i]=0;
				break;
			}
		}
	}
	bfs(s);
	printf("%d",d[t]-1);
	return 0;
}
