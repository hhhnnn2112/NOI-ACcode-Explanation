#include<bits/stdc++.h>
using namespace std;
long long b,p,k;
long long ksm(long long x,long long y,long long p)
{
	if(p==1)
	{
		return 0;
	}
	x%=p;
	long long ans=1;
	while(y)
	{
		if(y&1)
		{
			ans=ans*x%p;
		}
		x=x*x%p;
		y>>=1;
	}
	return ans;
}
int main()
{
	scanf("%lld%lld%lld",&b,&p,&k);
	printf("%lld^%lld mod %lld=%lld",b,p,k,ksm(b,p,k));
	return 0;
}
