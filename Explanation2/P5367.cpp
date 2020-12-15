#include<bits/stdc++.h>
using namespace std;
const int mod= 998244353;
int jc[1000010];
int tree[1000010];
int lowbit(int x)
{
	return x&-x;
}
int n;
void add(int x,int y)
{
	while(x<=n)
	{
		tree[x]+=y;
		x+=lowbit(x);
	}
}
int query(int x)
{
	int res=0;
	while(x>0)
	{
		res+=tree[x];
		x-=lowbit(x);
	}
	return res;
}
void init()
{
	jc[0]=1;
	for(int i=1;i<=1000000;i++)
	{
		jc[i]=(long long)jc[i-1]*i%mod;
	}
}
int ans=1;
int a[1000010];
int main()
{
	scanf("%d",&n);
	init();
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		add(i,1);
	}
	for(int i=1;i<=n;i++)
	{
		ans=(ans+(long long)query(a[i]-1)*jc[n-i]%mod)%mod;
		add(a[i],-1);
	}
	printf("%d",ans);
	return 0;
}
