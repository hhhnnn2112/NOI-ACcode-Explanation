#include<bits/stdc++.h>
using namespace std;
const int SUM=20,M=100005;//sum=18
int sum[SUM],n,dp[M];
int main()
{
	cin>>n;
	for(int i=1;i<=n;++i)
		dp[i]=n;
	for(int i=1;i<=18;++i)
		sum[i]=i*i*i*i;
	for(int i=1;i<=18;++i)
		for(int j=sum[i];j<=n;++j)
			dp[j]=min(dp[j],dp[j-sum[i]]+1);
	cout<<dp[n]<<endl;
	return 0;
}
