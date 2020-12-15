#include<bits/stdc++.h>
using namespace std;
const int N=8,M=1005;
int a[N],b[N]={0,1,2,3,5,10,20},dp[M]={1},tot,ans;
int main()
{
	for(int i=1;i<=6;++i)
	{
		cin>>a[i];
		tot+=a[i]*b[i];
	}
	for(int i=1;i<=6;++i)
		for(int k=1;k<=a[i];++k)
			for(int j=tot;j>=b[i];--j)
				dp[j]=max(dp[j],dp[j-b[i]]);
	for(int i=1;i<=tot;++i)
		if(dp[i])
			++ans;
	cout<<"Total="<<ans<<endl;
	return 0;
}
