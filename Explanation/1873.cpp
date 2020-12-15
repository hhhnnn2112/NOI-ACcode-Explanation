#pragma GCC optimize(3)
#include<cstdio>
#include<cmath>
#include<algorithm>
typedef long long ll;

using namespace std;

const int N=1000005;

ll n,m,a[N],ans;
ll l,r,mid;

inline ll totalHeight()
{
    ll ans=0;
    for(int i=1;i<=n;++i)
        if(a[i]>mid)
            ans=ans+a[i]-mid;
    return ans;
}

int main()
{
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;++i)
    {
        scanf("%lld",&a[i]);
        r=max(r,a[i]);
    }
    while(l<=r)
    {
        mid=(l+r)/2;
        ll tot=totalHeight();
        if(tot<m)
            r=mid-1;
        else
        {
            l=mid+1;
            ans=mid;
        }
    }
    printf("%lld\n",ans);
    return 0;
}