#include<bits/stdc++.h>
using namespace std;
const int N=1000005;
string s;
int n,a[N],dp[N],ans;//g=-1,r=1
int main()
{
	cin>>s;
	n=s.length();
	for(int i=1;i<=n;++i)//将G和R转化为-1和1，问题转化为求和为0的最长连续字串 
		if(s[i-1]=='R')
			a[i]=1;
		else
			a[i]=-1;
	for(int i=1;i<=n;++i)
		dp[i]=a[i]+dp[i-1];
	for(int i=1;i<=n;++i)
        for(int j=1;j<i;++j)
            if(dp[i]-dp[j-1]==0)
			{
                ans=max(ans,(i-j+1));//更新长度
                break;
            }
	printf("%d\n",ans);
	return 0;
}
