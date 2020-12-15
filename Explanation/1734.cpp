#include<bits/stdc++.h>
using namespace std;
const int N=1005;
int approx(int num)
{
	int tot=0;
	for(int x=1;x<num;++x)
		if(num%x==0)
			tot+=x;
	return tot;
}
int n,dp[N];
int main()
{
	cin>>n;
	for(int i=1;i<=n;++i)
		for(int j=n;j>=i;--j)
			dp[j]=max(dp[j],dp[j-i]+approx(i));
	cout<<dp[n]<<endl;
	return 0;
}
