#include<bits/stdc++.h>
using namespace std;
#define LL long long
LL xx,yy,ans;
LL exgcd(LL a,LL b,LL &xx,LL &yy)
{
	if(b==0)
	{
		xx=1;
		yy=0;
		return a;
	}
	ans=exgcd(b,a%b,xx,yy);
	LL t=xx;
	xx=yy;
	yy=t-(a/b)*yy;
	return ans;
}
LL x,y,m,n,l;
int main()
{
	scanf("%lld%lld%lld%lld%lld",&x,&y,&m,&n,&l);
	LL b=n-m;
	LL a=x-y;
	if(b<0)
	{
		b=-b;
		a=-a;
	}
	exgcd(b,l,xx,yy);
	if(a%ans!=0)
	{
		printf("Impossible");
	}
	else
	{
		printf("%lld",((xx*(a/ans))%(l/ans)+(l/ans))%(l/ans));
	}
	return 0;
}
