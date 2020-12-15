#include<bits/stdc++.h>
using namespace std;
int n,s,e;
int d[205];
int a[205];
queue<int> q;
int bfs(int st)
{
	q.push(st);
	d[st]=1;
	while(!q.empty())
	{
		int x=q.front();
		q.pop();
		if(x+a[x]<=n)
		{
			if(!d[x+a[x]])
			{
				d[x+a[x]]=d[x]+1;
				if(x+a[x]==e)
				{
					break;
				}
				q.push(x+a[x]);
			}
		}
		if(x-a[x]>=1)
		{
			if(!d[x-a[x]])
			{
				d[x-a[x]]=d[x]+1;
				if(x-a[x]==e)
				{
					break;
				}
				q.push(x-a[x]);
			}
		}
	}
	return d[e]==0?-1:d[e]-1;
}
int main()
{
	scanf("%d%d%d",&n,&s,&e);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("%d",bfs(s));
	return 0;
}
