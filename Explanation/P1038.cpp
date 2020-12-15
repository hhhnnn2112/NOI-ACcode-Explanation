#include<bits/stdc++.h>
using namespace std;
int in[105];
int n,p;
int c[105],u[105];
int check[105];
int head[105],ver[10050],nxt[10050],edge[10050],cnt;
void add(int x,int y,int z)
{
	ver[++cnt]=y;
	edge[cnt]=z;
	nxt[cnt]=head[x];
	head[x]=cnt;
}
void tupo()
{
	queue<int> q;
	for(int i=1;i<=n;i++)
	{
		if(c[i]&&!in[i])
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
			int y=ver[i],z=edge[i];
			c[y]+=z*c[x];
			in[y]--;
			if(!in[y])
			{
				c[y]-=u[y];
				if(c[y]>0)
				{
					q.push(y);
				}
			}
		}
	}
}
int main()
{
	scanf("%d%d",&n,&p);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&c[i],&u[i]);
	}
	for(int i=1;i<=p;i++)
	{
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		add(x,y,z);
		check[x]=1;
		in[y]++;
	}
	tupo();
	bool flag=1;
	for(int i=1;i<=n;i++)
	{
		if(!check[i])
		{
			if(c[i]>0)
			{
				flag=0;
				printf("%d %d\n",i,c[i]);
			}
		}
	}
	if(flag)
	{
		printf("NULL");
	}
	return 0;
}
