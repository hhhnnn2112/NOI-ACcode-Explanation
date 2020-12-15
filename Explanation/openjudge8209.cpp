#pragma GCC optimize(3)
#include<cstdio>

using namespace std;

const int N=100005;

int n,m,ans;
int l,r,mid;
int a[N];

inline int max(int a,int b)
{
    if(a>=b)
        return a;
    else
        return b;
}

inline int fun()
{
    int k=0,ans=1;
    for(int i=1;i<=n;++i)
        if(k+a[i]<=mid)
            k+=a[i];
        else
        {
            ++ans;
            k=a[i];
        }
    return ans;
}

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i)
    {
        scanf("%d",&a[i]);
        l=max(l,a[i]);
        r+=a[i];
    }
    while(l<=r)
    {
        mid=(l+r)/2;
        int team=fun();
        if(team<=m)
        {
            r=mid-1;
            ans=mid;
        }
        else
            l=mid+1;
    }
    printf("%d\n",ans);
    return 0;
}