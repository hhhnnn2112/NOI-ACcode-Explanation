#include<bits/stdc++.h>
using namespace std;
const int N=1005;
int n,a[N],dp[N],ans;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		scanf("%d",&a[i]);
		dp[i]=1;
	}
	for(int i=2;i<=n;++i)
		for(int j=1;j<i;++j)
			if(a[i]>a[j])
				dp[i]=max(dp[i],dp[j]+1);
	for(int i=1;i<=n;++i)
		ans=max(ans,dp[i]);
	ans=n-ans;
	printf("%d\n",ans);
	return 0;
}
