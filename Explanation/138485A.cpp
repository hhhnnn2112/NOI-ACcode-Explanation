#pragma GCC optimize(3)
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
typedef unsigned long long ll;
using namespace std;

ll n,m,ans;
ll l,r=1000000001,mid;

inline bool fastPower(ll base,ll power)
{
    ll result=1;
    while(power>0)
    {
        if(power&1)
            result=result*base;
        power>>=1; //降维
        base=(base*base);
    }
    if(result<=n)
        return true;
    else
        return false;
}

int main()
{
    scanf("%lld%lld",&n,&m); //x^m<=n
    if(m==1)
    {
        printf("%lld\n",n);
        return 0;
    }
    while(l<r)
    {
        mid=(l+r)/2; //二分查找x
        if(fastPower(mid,m))
        {
            l=mid;
            ans=mid;
        }
        else
            r=mid-1;
    }
    printf("%lld\n",ans);
    return 0;
}