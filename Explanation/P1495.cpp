#include<bits/stdc++.h>
using namespace std;
long long n,a[16],m[16],mi[16],mul=1,ans;
void exgcd(long long a,long long b,long long &x,long long &y)
{
	if(b==0)
	{
		x=1;
		y=0;
		return;
	}
	exgcd(b,a%b,x,y);
	long long tx=x;
	x=y;
	y=tx-a/b*y;
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>m[i];
		mul*=m[i];
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		mi[i]=mul/m[i];
		long long x=0,y=0;
		exgcd(mi[i],m[i],x,y);
		ans+=a[i]*mi[i]*((x+m[i])%m[i]);
	}
	cout<<ans%mul;
	return 0;
}
