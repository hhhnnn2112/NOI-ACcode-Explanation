#include<bits/stdc++.h>
using namespace std;
long long a1[105];
int a2[105];
int n,m;
int ans[1000005];
const int mod=1e9+7;
const int mod2=998244353;
long long  s1,s2;
int cnt;
void read()
{
	int f=1;
	s1=0;
	s2=0;
	char ch=getchar();
	while(ch>'9'||ch<'0')
	{
		if(ch=='-')
		{
			f=-1;
		}
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		s1=(s1*10+ch-'0')%mod;
		s2=(s2*10+ch-'0')%mod2;
		ch=getchar();
	}
	s1*=f;
	s2*=f;
}
bool calc(long long x)
{
	int sum=0;
	for(int i=n;i>=1;i--)
	{
		sum=((a1[i]+sum)*x)%mod;
	}
	sum=(sum+a1[0])%mod;
	return !sum;
}
bool calc2(long long x)
{
	int sum=0;
	for(int i=n;i>=1;i--)
	{
		sum=((a2[i]+sum)*x)%mod2;
	}
	sum=(sum+a2[0])%mod2;
	return !sum;
}
int main()
{
	read();
	n=s1;
	read();
	m=s1;
	for(int i=0;i<=n;i++)
	{
		read();
		a1[i]=s1;
		a2[i]=s2;
	}
	for(int i=1;i<=m;i++)
	{
		if(calc(i)&&calc2(i))
		{
			ans[++cnt]=i;
		}
	}
	printf("%lld\n",cnt);
	for(int i=1;i<=cnt;i++)
	{
		printf("%lld\n",ans[i]);
	}
	return 0;
}
