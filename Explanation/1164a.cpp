#include<bits/stdc++.h>
using namespace std;
const int N=105,M=10005;
int n,m,w[N],dp[M]={1};
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;++i)
		cin>>w[i];
	for(int i=1;i<=n;++i)
		for(int j=m;j>=w[i];--j)
			dp[j]=dp[j]+dp[j-w[i]];
	cout<<dp[m]<<endl;
	return 0;
}
