#pragma GCC optimize(3)
#include<cstdio>
typedef long double lf;

using namespace std;

const int N=200005,BIGN=100000005;

int n,x[N],y[N],s[N];
lf l,r=BIGN,mid;
lf ans;

inline bool Find()
{
    lf cnt=0.0;
    for(int i=1;i<=n;++i)
    {
        cnt+=s[i]/mid;
        if(cnt>y[i])
            return false;
        if(cnt<x[i])
            cnt=x[i];
    }
    return true;
}

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;++i)
        scanf("%d%d%d",&x[i],&y[i],&s[i]);
    while(l<=r-0.00001)
    {
        mid=(l+r)/2.0; //mid二分最小速度
        bool f=Find();
        if(f)
        {
            ans=mid;
            r=mid;
        }
        else
            l=mid;
    }
    printf("%.2Lf\n",ans);
    return 0;
}