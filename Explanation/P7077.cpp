#include<bits/stdc++.h>
using namespace std;
const int N=100005,mod=998244353;
int n,m,Q;
vector<int> g1[N],g2[N];
int cnt[N];
int data[N],tp[N],mul[N],add[N],pos[N];
int deg1[N];
void topu1()
{
	queue<int>q;
	for(int i=0;i<=m;i++)
	{
		deg1[i]=g2[i].size();
		if(deg1[i]==0)q.push(i);
	}
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		for(int i=0;i<g1[u].size();i++)
		{
			int v=g1[u][i];
			mul[v]=(long long)mul[v]*mul[u]%mod;
			deg1[v]--;
			if(deg1[v]==0)q.push(v);
		}
	}
}
int deg2[N];
void topuu2()
{
	queue<int>q;
	for(int i=0;i<=m;i++)
	{
		deg2[i]=g1[i].size();
		if(deg2[i]==0)q.push(i);
	}
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		int nowmul=1;
		for(int i=g2[u].size();i>0;i--)
		{
			int v=g2[u][i-1];
			cnt[v]=(cnt[v]+(long long)cnt[u]*nowmul)%mod;
			nowmul=(long long)nowmul*mul[v]%mod;
			deg2[v]--;
			if(deg2[v]==0)q.push(v);
		}
	}
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&data[i]);
	}
	scanf("%d",&m);
	mul[0]=1;
	for(int i=1;i<=m;i++)
	{
		scanf("%d",&tp[i]);
		if(tp[i]==1)
		{
			scanf("%d%d",&pos[i],&add[i]);
			mul[i]=1;
		}
		if(tp[i]==2)
		{
			scanf("%d",&mul[i]);
		}
		if(tp[i]==3)
		{
			mul[i]=1;
			int len=0;
			scanf("%d",&len);
			for(int j=0;j<len;j++)
			{
				int u;
				scanf("%d",&u);
				g1[u].push_back(i);
				g2[i].push_back(u);
			}
		}
	}
	scanf("%d",&Q);
	cnt[0]=1;
	for(int i=0;i<Q;i++)
	{
		int u;
		scanf("%d",&u);
		g2[0].push_back(u);
		g1[u].push_back(0);
	}
	topu1();
//	for(int i=0;i<=n;i++)
//	{
//		printf("%d ",mul[i]);
//	}
//	return 0;
	topuu2();
	for(int i=1;i<=n;i++)
	{
		data[i]=(long long)data[i]*mul[0]%mod;
	}
	for(int i=1;i<=m;i++)
	{
		if(tp[i]==1)
		{
			data[pos[i]]=(data[pos[i]]+(long long)cnt[i]*add[i])%mod;
		}
	}
	for(int i=1;i<=n;i++)
	{
		printf("%d ",data[i]);
	}
	return 0;
}
