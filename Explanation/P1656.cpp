#include<bits/stdc++.h>
using namespace std;
int f[160];
int find(int k)
{
	if(f[k]==k)
	{
		return f[k];
	}
	return f[k]=find(f[k]);
}
int n,m;
set<pair<int,int > > s;
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		if(x>y)
		{
			swap(x,y);
		}
		s.insert(make_pair(x,y));
	}
	for(set<pair<int,int > > ::iterator i=s.begin();i!=s.end();i++)
	{
		for(int j=1;j<=n;j++)
		{
			f[j]=j;
		}
		for(set<pair<int,int > > ::iterator j=s.begin();j!=s.end();j++)
		{
			if(i==j)continue;
			f[find(j -> first )]=find(j -> second);
		}
		for(int j=1;j<n;j++)
		{
			if(find(f[j])!=find(f[j+1]))
			{
				printf("%d %d\n",i -> first,i -> second);
				break;
			}
		}
	}
	return 0;
}
