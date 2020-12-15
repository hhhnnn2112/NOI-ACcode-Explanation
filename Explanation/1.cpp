#include<bits/stdc++.h>
using namespace std;
const int N=100005;
const int M=100005;
int cnt,n,m;
int head[N],nxt[M],ver[M];
void add(int x,int y)
{
	ver[++cnt]=y;
	nxt[cnt]=head[x];
	head[x]=cnt;
}
int in[N];
int out[N];
int d[N];
void tupo()
{
	queue<int> q;
	for(int i=1;i<=n;i++)
	{
		if(in[i]==0)
		{
			q.push(i);
			d[i]=1;
		}
	}
	while(!q.empty())
	{
		int x=q.front();
		q.pop();
		for(int i=head[x];i;i=nxt[i])
		{
			int y=ver[i];
			d[y]+=d[x];
			if(--in[y]==0)
			{
				q.push(y);
			}
		}
	}
}
int main()
{
	scanf("%d",&n);
	int x,y;
	while(scanf("%d%d",&x,&y)!=EOF)
	{
		add(x,y);
		in[y]++;
		out[x]++;
	}
	tupo();
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		if(out[i]==0)
		{
			ans+=d[i];
		}
	}
	printf("%d",ans);
	return 0;
}
//food web
