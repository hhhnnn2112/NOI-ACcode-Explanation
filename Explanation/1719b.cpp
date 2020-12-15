#include<bits/stdc++.h>
using namespace std;
const int N=125;
int n,a[N][N],sum[N][N],dp[N],s[N],ans=-1<<30;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			scanf("%d",&a[i][j]);
	for(int i=1;i<=n;++i)//i=行 
		for(int j=1;j<=n;++j)//j=列
			sum[i][j]=a[i][j]+sum[i-1][j];
	for(int i=1;i<=n;++i)
		for(int j=i;j<=n;++j)//按行定位
			for(int k=1;k<=n;++k)
			{
				s[k]=sum[j][k]-sum[i-1][k];
				dp[k]=max(s[k],s[k]+dp[k-1]);
				ans=max(ans,dp[k]);
			}
	printf("%d\n",ans);
	return 0;
}
