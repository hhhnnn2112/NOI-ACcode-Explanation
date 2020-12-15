#include<bits/stdc++.h>
using namespace std;
const long long N=1e4+3;
long long n;
long long p[10005];
long long f[100005];
long long q[100005];
long long k=0;
long long ans;
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
	scanf("%lld",&n);
	if(n==1)
	{
		printf("1");
		return 0;
	}
	init();
	f[0]=1;
	for(long long i=1;i<=k;i++)
	{
		for(long long j=n;j>=q[i];--j)
		{
			long long tmp=q[i];
			while(tmp<=j)
			{
				f[j]+=f[j-tmp];
				tmp*=q[i];
			}
		}
	}
	for(long long i=1;i<=n;i++)
	{
		ans+=f[i];
	}
	printf("%lld",ans+1);
	return 0;
}
