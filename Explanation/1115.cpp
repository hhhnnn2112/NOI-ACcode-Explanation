#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int n,a[N],dp[N],ans;//dp[i]代表以i为终点，前面的最大字段和 
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d",&a[i]);
	ans=dp[1]=a[1];
	for(int i=2;i<=n;++i)
		dp[i]=max(a[i],a[i]+dp[i-1]);
	for(int i=1;i<=n;++i)
		ans=max(ans,dp[i]);
	printf("%d\n",ans);
	return 0;
}
