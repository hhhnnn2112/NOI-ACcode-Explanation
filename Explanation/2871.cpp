#include<bits/stdc++.h>
using namespace std;
const int V=12885,WEI=3405;
int n,m,c[WEI],w[WEI],dp[V];
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;++i)
		cin>>c[i]>>w[i];
	for(int i=1;i<=n;++i)
		for(int j=m;j>=c[i];--j)
				dp[j]=max(dp[j],dp[j-c[i]]+w[i]);
	cout<<dp[m]<<endl;
	return 0;
}
