#include<bits/stdc++.h>
using namespace std; 
queue<int > q;
const int M=2e5+5;
const int N=3e5+5;
vector<int> adj[N],son[N];
int n,m;
int fa[N];
int group[N];
int gf(int k)
{
	if(fa[k]==k)
	{
		return k;
	}
	return gf(fa[k]);
}
int merge(int x,int y)
{
	int f=fa[x],g=fa[y];
	if(son[g].size()>son[f].size())
	{
		swap(f,g);
	}
	for(int v=0;v<son[g].size();v++)
	{
		fa[son[g][v]]=f;
		son[f].push_back(son[g][v]);
	}
	for(int v=0;v<adj[g].size();v++)
	{
		adj[f].push_back(adj[g][v]);
	}
	if(adj[f].size()>1)
	{
		q.push(f);
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		adj[a].push_back(b);
	}
	for(int i=1;i<=n;i++)
	{
		fa[i]=i;
		son[i].push_back(i);
		if(adj[i].size()>1)
		{
			q.push(i);
		}
	}
	while(!q.empty())
	{
		int qf=q.front();
		q.pop();
		while(adj[qf].size()>1)
		{
			int last=adj[qf][adj[qf].size()-1];
			adj[qf].pop_back();
			if(fa[last]!=fa[adj[qf][adj[qf].size()-1]])
			{
				merge(last,adj[qf][adj[qf].size()-1]);
			}
		}
	}
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		if(!group[fa[i]])
		{
			group[fa[i]]=++cnt;
		}
		printf("%d\n",group[fa[i]]);
	}
	return 0;
}
