#include<bits/stdc++.h>
using namespace std;
int n,m;
const int N=1050;
const int M=1000005;
int head[N],nxt[M],ver[M];
int cnt;
void add(int x,int y)
{
	ver[++cnt]=y;
	nxt[cnt]=head[x];
	head[x]=cnt;
}
int d[N],in[N];
int v[N];
int ans;
int s[N][N],pd[N][N];
void tupo()
{
	queue<pair<int,int> > q;
	for(int i=1;i<=n;i++)
	{
		//cout<<i<<' '<<in[i]<<' '<<ou[i]<<endl;
		if(in[i]==0)
		{
			q.push(make_pair(i,1));
		}
	}
	while(!q.empty())
	{
		int x=q.front().first;
		int t=q.front().second;
		q.pop();
		for(int i=head[x];i;i=nxt[i])
		{
			int y=ver[i];
			in[y]--;
			if(in[y]==0)
			{
				q.push(make_pair(y,t+1));
				ans=max(ans,t+1);
			}
		}
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int t;
		scanf("%d",&t);
		memset(v,0,sizeof v);
		for(int j=1;j<=t;j++)
		{
			int x;
			scanf("%d",&x);
			s[i][j]=x;
			v[x]=1;
		}
		for(int j=s[i][1];j<=s[i][t];j++)
		{
			if(v[j])continue;
			for(int k=1;k<=t;k++)
			{
				if(!pd[j][s[i][k]])
				{
					pd[j][s[i][k]]=1;
					in[s[i][k]]++;
					add(j,s[i][k]);
				}
			}
		}
	}
	tupo();
	printf("%d",ans);
	return 0;
}
