#pragma GCC optimize(3)
#include<cstdio>
#include<cmath>
#include<algorithm>

using namespace std;

const int N=10005;

int n,k;
int l,r,mid,ans;
int a[N];

inline int totalLine()
{
    int ans=0;
    for(int i=1;i<=n;++i)
        ans=ans+int(a[i]/mid);
    return ans;
}

int main()
{
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;++i)
    {
        double num;
        scanf("%lf",&num);
        a[i]=int(num*100);
        r=max(r,a[i]);
    }
    while(l<=r)
    {
        mid=(l+r)/2;
        if(!mid)
        {
            printf("0.00\n");
            return 0;
        }
        int cnt=totalLine();
        if(cnt<k)
            r=mid-1;
        else
        {
            l=mid+1;
            ans=mid;
        }
    }
    if(ans>=1)
        printf("%.2lf\n",ans/100.0);
    else
        printf("0.00\n");
    return 0;
}