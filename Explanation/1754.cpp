#include<bits/stdc++.h>
using namespace std;
const int N=23;
long long n,dp[N][N];
int main()
{
	cin>>n;
	for(int i=1;i<=n;++i)
		dp[i][0]=1;
	for(int i=1;i<=n;++i)
		for(int j=1;j<=i;++j)
			if(i>=j+1)
				dp[i][j]=dp[i-1][j]+dp[i][j-1];
			else
				dp[i][j]=dp[i][j-1];
	cout<<dp[n][n]<<endl;
	return 0;
}
