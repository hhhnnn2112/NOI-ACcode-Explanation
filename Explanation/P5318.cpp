#include <bits/stdc++.h>
using namespace std;
vector< int > a[100006];
bool d[1000005],b[1000006];
int n,m;
void dfs(int x)
{
	if(!d[x])
	{
		cout<<x<<" ";
		d[x]=1;
	}
	else
	{
		return;
	}
	for(int i=0;i<a[x].size();i++)
	{
		dfs(a[x][i]);
	}
}
void bfs()
{
	queue<int > q;
	q.push(1);
	while(!q.empty())
	{
		int x=q.front();
		q.pop();
		if(b[x])
		{
			continue;
		}
		else
		{
			b[x]=1;
			cout<<x<<" ";
		}
		for(int i=0;i<a[x].size();i++)
		{
			q.push(a[x][i]);
		}
	}
}
int main()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		int x,y;
		cin>>x>>y;
		a[x].push_back(y);
	}
	for(int i=1;i<=n;i++)
	{
		sort(a[i].begin(),a[i].end());
	}
	dfs(1);
	cout<<endl;
	bfs();
	return 0;
}
