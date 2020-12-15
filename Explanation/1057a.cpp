#include<bits/stdc++.h>
using namespace std;
const int N=35;
int n,m,dp[N][N];
int main()
{
	cin>>n>>m;
	dp[0][1]=1;//初始状态下小蛮手中有球 
	for(int i=1;i<=m;++i)
		for(int j=1;j<=m;++j)
		{
			if(j==1)
                dp[i][j]=dp[i-1][n]+dp[i-1][2];
            else if(j==n)
                dp[i][j]=dp[i-1][1]+dp[i-1][n-1];
            else
                dp[i][j]=dp[i-1][j-1]+dp[i-1][j+1];
		}
	printf("%d\n",dp[m][1]);
	return 0;
}
