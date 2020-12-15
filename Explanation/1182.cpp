#pragma GCC opcntize(3)
#include<cstdio>
#include<algorithm>
#include<cmath>

using namespace std;

const int N=100005;

int n,m,a[N];
int l,r,mid;

inline bool find(int x,int a[])
{
    int cnt=0,total=0;
    for(int i=1;i<=n;++i)
        if(total+a[i]<=x)
            total+=a[i];
        else
        {
            total=a[i];
            ++cnt;
        }
    if(cnt>=m)
        return 1;
    else
        return 0;
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
        if(find(mid,a))
            l=mid+1;
        else
            r=mid-1;
    }
    printf("%d\n",l);
    return 0;
}