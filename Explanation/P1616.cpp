#include<bits/stdc++.h>
#define int long long
using namespace std;
int f[10000050],v[10010],w[10010];
int t,m;
signed main()
{
	cin>>t>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i]>>v[i];
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=w[i];j<=t;j++)
		{
			f[j]=max(f[j],f[j-w[i]]+v[i]);
		}
	}
	cout<<f[t];
	return 0;
}
