#include<bits/stdc++.h>
using namespace std;
const int N=2005;
int n,m,a[N][N],dp[N][N],ans=1<<30;
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;++i)
		for(int j=1;j<=n;++j)
			scanf("%d",&a[i][j]);
	for(int j=1;j<=n;++j)//同行 
		for(int i=1;i<=m;++i)//同列 
		{
			if(i!=1)
				dp[i][j]=min(dp[i][j-1],dp[i-1][j-1])+a[i][j];
			else
				dp[i][j]=min(dp[i][j-1],dp[m][j-1])+a[i][j];
		}
	for(int i=1;i<=m;++i)
		ans=min(ans,dp[i][n]);
	printf("%d\n",ans);
	return 0;
}
