#include<bits/stdc++.h>
using namespace std;
#define LL long long
LL a,b,c,x,y;
LL gcd(LL a,LL b)
{
	if(b==0)
	{
		return a;
	}
	return gcd(b,a%b);
}
void exgcd(LL a,LL b,LL &x,LL &y)
{
	if(b==0)
	{
		x=1;
		y=0;
		return;
	}
	exgcd(b,a%b,x,y);
	LL t=x;
	x=y;
	y=t-(a/b)*y;
	return ;
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%lld%lld%lld",&a,&b,&c);
		x=y=0;
		LL g=gcd(a,b);
		if(c%g)printf("-1\n");
		else
		{
			a/=g;
			b/=g;
			c/=g;
			exgcd(a,b,x,y);
			x*=c;
			y*=c;
			x=(x%b+b)%b;
			if(x==0)
			{
				x=b;
			}
			y=(c-a*x)/b;
			if(y>0)
			{
				LL xmin,xmax,ymin,ymax;
				xmin=x,ymax=y;
				y%=a;
				if(y==0)
				{
					y=a;
				}
				x=(c-b*y)/a;
				xmax=x,ymin=y;
				printf("%lld %lld %lld %lld %lld\n",(xmax-xmin)/b+1,xmin,ymin,xmax,ymax);
			}
			else
			{
				LL xmin,ymin;
				xmin=x;
				y=y%a+a;
				ymin=y;
				printf("%lld %lld\n",xmin,ymin);
			}
		}
	}
	return 0;
}
