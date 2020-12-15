#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int n,dp[N][2],a[N];//0代表波谷，1代表波峰 
int main()
{
	dp[1][0]=dp[1][1]=1;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d",&a[i]);
	for(int i=2;i<=n;++i)
	{
		if(a[i]<a[i-1])
			dp[i][0]=dp[i-1][1]+1;
		else
			dp[i][0]=dp[i-1][0];
		if(a[i]>a[i-1])
			dp[i][1]=dp[i-1][0]+1;
		else
			dp[i][1]=dp[i-1][1];
	}
	printf("%d\n",max(dp[n][1],dp[n][0]));
	return 0;
}
