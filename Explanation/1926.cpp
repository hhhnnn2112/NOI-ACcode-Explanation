#include<bits/stdc++.h>
using namespace std;
const int N=15,M=155;
int n,m,k,r,task[N],dp[M],w[N],v[N],t,ans;
int main()
{
	cin>>n>>m>>k>>r;
	for(int i=1;i<=n;++i)
		cin>>task[i];
	sort(task+1,task+n+1);
	for(int i=1;i<=m;++i)
		cin>>w[i];
	for(int i=1;i<=m;++i)
		cin>>v[i];
	for(int i=1;i<=m;++i)
		for(int j=r;j>=w[i];--j)
			dp[j]=max(dp[j],dp[j-w[i]]+v[i]);
	for(int i=1;i<=r;++i)
		if(dp[i]>=k)
		{
			t=i;
			break;
		}
	r-=t;
	int i=0;
	while(r>0)
	{
		++i;
		r-=task[i];
		if(r>=0)
			++ans;
	}
	cout<<ans<<endl;
	return 0;
}
