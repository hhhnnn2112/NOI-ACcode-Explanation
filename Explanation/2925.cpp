#include<bits/stdc++.h>
using namespace std;
const int N=50005,H=5005;
int c,h,a[H],val[H],dp[N];
int main()
{
	cin>>c>>h;
	for(int i=1;i<=h;++i)
	{
		cin>>a[i];
		val[i]=a[i];
	}
	for(int i=1;i<=h;++i)
		for(int j=c;j>=a[i];--j)
		{
			dp[j]=max(dp[j],dp[j-a[i]]+val[i]);
			if(dp[j]==c)
			{
				cout<<dp[j]<<endl;
				return 0;
			}
		}	
	cout<<dp[c]<<endl;
	return 0;
}
