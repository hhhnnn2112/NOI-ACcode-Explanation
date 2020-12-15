#include<bits/stdc++.h>
using namespace std;
const int V=505,WEI=45005;
int n,m,c[WEI],dp[V];
int main()
{
	cin>>m>>n;
	for(int i=1;i<=n;++i)
		cin>>c[i];
	for(int i=1;i<=n;++i)
		for(int j=m;j>=c[i];--j)
			dp[j]=max(dp[j],dp[j-c[i]]+c[i]);
	cout<<dp[m]<<endl;
	return 0;
}
