#include<bits/stdc++.h>
using namespace std;
const int N=10005;
int m,n,w[N],v[N],dp[N];
int main()
{
	cin>>m>>n;
	for(int i=1;i<=n;++i)
		cin>>v[i]>>w[i];
	for(int i=1;i<=n;++i)
		for(int j=w[i];j<=m;++j)
			dp[j]=max(dp[j],dp[j-w[i]]+v[i]);
	cout<<dp[m]<<endl; 
	return 0;
}
