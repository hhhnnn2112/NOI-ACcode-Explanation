#include<bits/stdc++.h>
using namespace std;
const int N=55,M=405;
int size,wei,val,dp[M][M],maxsize,maxwei,n;
int main()
{
	cin>>maxsize>>maxwei>>n;
	for(int i=1;i<=n;++i)
	{
		cin>>size>>wei>>val;
		for(int j=maxsize;j>=size;--j)
			for(int k=maxwei;k>=wei;--k)
				dp[j][k]=max(dp[j][k],dp[j-size][k-wei]+val);
	}
	cout<<dp[maxsize][maxwei]<<endl; 
	return 0;
}
