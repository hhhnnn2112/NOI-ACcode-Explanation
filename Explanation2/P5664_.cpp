#include<bits/stdc++.h>
using namespace std;
int n,m;
long long s[120],z=1,f[120][2200];
const int mod=998244353;
int a[405][2050]; 
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			scanf("%d",&a[i][j]);
			s[i]=(s[i]+a[i][j])%mod;
		}
		z=z*(s[i]+1)%mod;
	}
	z--;//不考虑第三个条件 
	for(int k=0;k<m;k++)
	{
		memset(f,0,sizeof f);
		f[0][0]=1;
		for(int i=0;i<n;i++)
		{
			for(int j=-i;j<=i;j++)
			{
				f[i+1][j]=(f[i+1][j]+f[i][j])%mod;//buxuan
				f[i+1][j+1]=(f[i+1][j+1]+f[i][j]*a[i][k])%mod;//xuan k hang de
				f[i+1][j-1]=(f[i+1][j-1]+f[i][j]*(s[i]-a[i][k]))%mod;//xuan fei k hang de
			}
		}
		for(int j=1;j<=n;j++)
		{
			z=(z+mod-f[n][j])%mod;
		}
	}
	printf("%lld",z);
	return 0;
} 
