#include<bits/stdc++.h>
using namespace std;
const int N=35,V=20005;
int v,n,a[N],val[N],dp[N][V];
int main()
{
	cin>>v>>n;
	for(int i=1;i<=n;++i)
	{
		cin>>a[i];
		val[i]=a[i];
	} 
	for(int i=1;i<=n;++i)
		for(int j=0;j<=v;++j)
			if(j>=a[i])
				dp[i][j]=max(dp[i-1][j],dp[i-1][j-a[i]]+val[i]);
			else
				dp[i][j]=dp[i-1][j];
	cout<<v-dp[n][v]<<endl;
	return 0;
}
