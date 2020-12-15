#include<bits/stdc++.h>
using namespace std;
const long long N=1e4+3;
long long n;
long long p[10005];
long long f[100005];
long long q[100005];
long long k=0;
long long ans,mod;
void init()
{
	memset(p,1,sizeof p);
	p[0]=p[1]=0;
	for(long long i=2;i<=n;i++)
	{
		if(p[i])
		{
			for(long long j=2;j*i<=n;j++)
			{
				p[j*i]=0;
			}
			q[++k]=i;
		}
	}
}
int main()
{
	scanf("%lld %lld",&n,&mod);
	if(n==1)
	{
		printf("1");
		return 0;
	}
	init();
	for(int i=0;i<=n;i++)
	{
		f[i]=1;
	}
	for(long long i=1;i<=k;i++)
	{
		for(long long j=n;j>0;j--)
		{
			for(long long k=q[i];k<=j;k*=q[i])
			{
				f[j]=(f[j]+f[j-k]*k)%mod;
			}
		}
	}
	printf("%lld",f[n]);
	return 0;
}
