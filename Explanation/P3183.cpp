#include<bits/stdc++.h>
using namespace std;
int in[100500],out[100500];
int d[100500];
int head[100500],ver[200500],nxt[205000],cnt;
void add(int x,int y)
{
	ver[++cnt]=y;
	nxt[cnt]=head[x];
	head[x]=cnt;
}
int dfs(int x)
{
	if(d[x])return d[x];
	int ans=0;
	if(!out[x]&&in[x])
	{
		ans++;
	}
	for(int i=head[x];i;i=nxt[i])
	{
		ans+=dfs(ver[i]);
	}
	d[x]=ans;
	return ans;
}
int n,m;
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		add(x,y);
		out[x]++;
		in[y]++;
	}
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		if(!in[i])
		{
			ans+=dfs(i);
		}
	}
	printf("%d",ans);
	return 0;
}
