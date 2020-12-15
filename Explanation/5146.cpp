#include<bits/stdc++.h>
using namespace std;
const int N=1000005;
int n,a[N],dp[N],ans;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d",&a[i]);
	dp[1]=a[1];
	for(int i=2;i<=n;++i)
	{
		dp[i]=min(a[i],dp[i-1]);
		ans=max(ans,a[i]-dp[i]);
	}
	printf("%d\n",ans);
	return 0;
}
