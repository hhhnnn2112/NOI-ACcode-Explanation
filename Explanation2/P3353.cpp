#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[2000150];
int fae,pre[2000150];
int aaa;
int x,v;
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>x>>v;
		a[x]+=v;
		fae=max(fae,x);
	}
	for(int i=1;i<=fae;i++ )
	{
		pre[i]+=pre[i-1]+a[i];
	}
	for(int i=1;i<=fae;i++)
	{
		aaa=max(aaa,pre[i+m]-pre[i]);
	}
	cout<<aaa;
	return 0;
	return 0;
}
