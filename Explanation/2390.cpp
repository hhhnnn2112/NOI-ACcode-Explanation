#pragma GCC optimize(3)
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
typedef long long ll;

using namespace std;

const int N=50005,M=1000000005;

int t,n,a[N],ans;
int l=1,r,mid;

inline bool Find(int mid)
{
    int ans=0;
    for(int l=1;l<=n;++l) //以l作为左端地标的位置
    {
        int r=mid+l-1; //以r作为右端地标的位置
        if(r>n || (a[l]>0 && a[l-1]>0) || (a[r]<0 && a[r+1]<0))
            continue;
        if(a[r]<=0) //只往左
            ans=-a[l];
        else if(a[l]>=0) //只往右
            ans=a[r];
        else //左右
        {
            if(-a[l]>a[r]) //先右后左
                ans=-a[l]+2*a[r];
            else //先左后右
                ans=a[r]-2*a[l];
        }
        if(ans<=t)
            return true;
    }
    return false;
}

int main()
{
    scanf("%d%d",&t,&n);
    r=n;
    for(int i=1;i<=n;++i)
        scanf("%d",&a[i]);
    sort(a+1,a+n+1);
    while(l<=r)
    {
        mid=(l+r)/2; //访问mid个地标
        bool f=Find(mid);
        if(f)
        {
            ans=mid;
            l=mid+1;
        }
        else
            r=mid-1;
    }
    printf("%d\n",ans);
    return 0;
}