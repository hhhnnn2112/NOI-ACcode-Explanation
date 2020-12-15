#include<bits/stdc++.h>
using namespace std;
const int N=1000005;
long long n,p,a[N],dp[N],fea[N],pts[N];//dp[i]代表以i为终点，前面的最大字段和 
int main()//fea代表特征值，pts代表分数
{
	scanf("%lld%lld",&n,&p);
	for(int i=1;i<=n;++i)
		scanf("%lld",&a[i]);
	dp[1]=a[1];
	for(int i=2;i<=n;++i)
		dp[i]=max(a[i],a[i]+dp[i-1]);
	fea[1]=dp[1];
	for(int i=2;i<=n;++i)
		fea[i]=max(fea[i-1],dp[i]);
	pts[1]=fea[1];
	pts[2]=pts[1]+fea[1];
	for(int i=3;i<=n;++i)
		pts[i]=max(pts[i-1]+fea[i-1],pts[i-1]);
	printf("%lld\n",max(pts[n],pts[1])%p);
	return 0;
}
