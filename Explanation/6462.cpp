#include<cstdio>
typedef long long ll;

using namespace std;

ll h,x,y,t;

int main()
{
    scanf("%lld",&t);
	while(t--)
    {
		scanf("%lld%lld%lld",&h,&x,&y);
		if(y>=h)
        {
            printf("Yes\n");
            continue;
        }
		if(x>=h)
        {
            printf("No\n");
            continue;
        }
		if(y==0)
        {
            printf("No\n");
            continue;
        }
		if(x==0)
        {
            printf("Yes\n");
            continue;
        }
		ll attack=h/x+1;
		h%=x;
		if(!h)
            h=x;
		if(attack*y>=h)
            printf("Yes\n");
		else
            printf("No\n");
	}
}