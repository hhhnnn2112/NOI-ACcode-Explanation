#pragma GCC optimize(3)
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

const int N=100005;

int n,m,k,ans;
int l=1,r,mid;
int a[N];

inline int Longest(int x)
{
    int ans=0;
    for(register int i=n;i>=1;--i)
        if(a[i]/x)
            ans+=a[i]/x;
        else
            return ans;
    return ans;
}

int main()
{
    scanf("%d%d",&n,&k);
    for(register int i=1;i<=n;++i)
        scanf("%d",&a[i]);
    sort(a+1,a+n+1);
    r=a[n];
    while(l<=r)
    {
        mid=(l+r)/2;
        int cur=Longest(mid);
        if(cur>=k)
        {
            l=mid+1;
            ans=mid;
        }
        else
            r=mid-1;
    }
    printf("%d\n",ans);
    return 0;
}