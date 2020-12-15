#include<bits/stdc++.h>
using namespace std;
int jc[1000050];
const int mod=998244353;
void init()
{
	jc[0]=1;
	for(int i=1;i<=1000000;i++)
	{
		jc[i]=(long long )jc[i-1]*i%mod;
	}
}
int t[1000500],n,a[1000050];
int lowbit(int x)
{
	return x&-x;
}
void add(int x,int y)
{
	while(x<=n)
	{
		t[x]+=y;
		x+=lowbit(x);
	}
}
int query(int x)
{
	int res=0;
	while(x>0)
	{
		res+=t[x];
		x-=lowbit(x);
	}
	return res;
}
int ans=0;
int main()
{
	init();
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		add(i,1);
	}
	for(int i=1;i<=n;i++)
	{
		ans=(ans+(long long)query(a[i]-1)*jc[n-i])%mod;
		add(a[i],-1);
	}
	printf("%d",ans+1);
	return 0;
}
