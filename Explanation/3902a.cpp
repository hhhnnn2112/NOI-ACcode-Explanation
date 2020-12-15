#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int n,a[N],dp[N],ans;//dp[i]代表最长上升子序列长度为i的末尾最小值 
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;++i)
		if(a[i]>dp[ans])
		{
			++ans;
			dp[ans]=a[i];
		}
		else
		{
			int l=1,r=ans;
			while(l<r)
			{
				int mid=(l+r)/2;
				if(dp[mid]>a[i])
					r=mid;
				else
					l=mid+1;
			}
			dp[l]=a[i];
		}
	cout<<n-ans<<endl;
	return 0;
}
