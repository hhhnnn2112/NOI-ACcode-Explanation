#include <bits/stdc++.h>
using namespace std;
int v[1050],w[1050],f[10050];
int t,m;
int main()
{
	cin>>t>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i]>>v[i];
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=t;j>=w[i];j--)
		{
			f[j]=max(f[j],f[j-w[i]]+v[i]);
		}
	}
	cout<<f[t];
	return 0;
}
