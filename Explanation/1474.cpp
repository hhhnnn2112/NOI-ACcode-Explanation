#include<bits/stdc++.h>
using namespace std;
const int N=27,M=10005;
long long v,n,a[N],dp[M]={1};
using namespace std;
int main()
{
	cin>>v>>n;
	for(int i=1;i<=v;++i)
		cin>>a[i];
	for(int i=1;i<=v;++i)
		for(int j=a[i];j<=n;++j)
			dp[j]+=dp[j-a[i]];
	cout<<dp[n]<<endl;
	return 0;
}
