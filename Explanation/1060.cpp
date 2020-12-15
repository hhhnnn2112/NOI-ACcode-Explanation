#include<bits/stdc++.h>
using namespace std;
const int N=30,M=30005;
int w[N],v[N],dp[M],n,m;
int main()
{
	cin>>m>>n;
	for(int i=1;i<=n;++i)
	{
		cin>>v[i]>>w[i];
		w[i]*=v[i]; 
	} 
	for(int i=1;i<=n;++i)
		for(int j=m;j>=v[i];--j)
			dp[j]=max(dp[j],dp[j-v[i]]+w[i]);
	cout<<dp[m]<<endl;
	return 0;
}
