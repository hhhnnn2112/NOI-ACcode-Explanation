#include<bits/stdc++.h>
using namespace std;
const int N=205;
int n,m,x,y,a[N][N],dp[N][N],ans;
int main()
{
	scanf("%d%d",&n,&m);
	
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			scanf("%d",&a[i][j]);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			dp[i][j]=max(dp[i-1][j],max(dp[i-1][j-1],dp[i-1][j+1]))+a[i][j];
	x=n;
	y=m/2+1;
	ans=max(dp[x][y],max(dp[x][y-1],dp[x][y+1]));
	printf("%d\n",ans);
	return 0;
} 
