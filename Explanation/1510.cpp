#include<bits/stdc++.h>
using namespace std;
const int N=10005;
int v,n,c,dp[N],wei[N],val[N],ans;
bool f;
int main()
{
	cin>>v>>n>>c;
	for(int i=1;i<=n;++i)
	{
		cin>>val[i]>>wei[i];
		for(int j=v;j>=wei[i];--j)
			dp[j]=max(dp[j],dp[j-wei[i]]+val[i]);
	}
	f=false;
    for(int i=1;i<=c;++i)
    	if(dp[i]>=v)
    	{
        	ans=i;
        	f=true;
        	break;
    	}
    if(f)
    	cout<<c-ans<<endl;
    else
		cout<<"Impossible"<<endl;
    return 0;    
}
