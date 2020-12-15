#include<bits/stdc++.h>
using namespace std;
const int N=100500;
int head[N],ver[N<<2],edge[N<<2],nxt[N<<2],cnt;
int from[N<<2];
int in[N];
void add(int x,int y,int z)
{
	ver[++cnt]=y;
	edge[cnt]=z;
	nxt[cnt]=head[x];
	from[cnt]=x;
	head[x]=cnt;
}
int n,a,b;
int tupo()
{
	queue<int> q;
	for(int i=1;i<=n;i++)
	{
		if(!in[i])
		{
			q.push(i);
		}
	}
	while(!q.empty())
	{
		int x=q.front();
		q.pop();
		for(int i=head[x];i;i=nxt[i])
		{
			int y=ver[i];
			int z=edge[i];
			if(z==1)
			{
				edge[i^1]=2;
			}
			if(z==0)
			{
				in[y]--;
				if(!in[y])
				{
					q.push(y);
				}
			}
		}
	}
}
int main()
{
	scanf("%d%d%d",&n,&a,&b);
	for(int i=1;i<=a;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		add(x,y,0);
		in[y]++;
	}
	if((cnt&1)==0)cnt++;
	for(int i=1;i<=b;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		add(x,y,1);
		add(y,x,1);
	}
	tupo();
	for(int i=1;i<=cnt;i++)
	{
		if(edge[i]==1)
		{
			printf("%d %d\n",from[i],ver[i]);
		}
	}
	return 0;
}
