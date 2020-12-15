#include<bits/stdc++.h>
using namespace std;
const int N=10005,T=10000005;
int t,m,w[N],v[N],dp[T];
int main()
{
	cin>>t>>m;
	for(int i=1;i<=m;++i)
		cin>>w[i]>>v[i];
	for(int i=1;i<=m;++i)
		for(int j=w[i];j<=t;++j)
			dp[j]=max(dp[j],dp[j-w[i]]+v[i]);
	cout<<dp[t]<<endl;
	return 0;
}
