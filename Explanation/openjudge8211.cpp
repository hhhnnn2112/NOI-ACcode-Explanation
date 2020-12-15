#pragma GCC optimize(3)
#include<cstdio>
#include<cmath>
#include<algorithm>

using namespace std;

const int N=10005;
const double pi=acos(-1);

int n,f,a;
double l,r,mid,ans;
double cake[N];

inline int totalCake()
{
    int ans=0;
    for(int i=1;i<=n;++i)
        ans=ans+int(cake[i]/mid);
    return ans;
}

int main()
{
    scanf("%d%d",&n,&f);
    ++f;
    for(int i=1;i<=n;++i)
    {
        scanf("%d",&a);
        cake[i]=a*a*pi;
        r=max(r,cake[i]);
    }
    while(l<=r-0.00001)
    {
        mid=(l+r)/2.0;
        int cnt=totalCake();
        if(cnt<f)
            r=mid;
        else
        {
            ans=mid;
            l=mid;
        }
    }
    printf("%.3lf\n",ans);
    return 0;
}