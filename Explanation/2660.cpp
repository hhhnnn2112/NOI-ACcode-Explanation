#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>

using namespace std;

typedef long long ll;

ll x,y,tot,change;

int main()
{
    scanf("%lld%lld",&x,&y);
    while(x&&y)
    {
        tot+=(y/x)*4*x;
        change=x;
        x=y%x;
        y=change;
    }
    printf("%lld\n",tot);
    return 0;
}
