#pragma GCC optimize(3)
#include<cstdio>
#include<algorithm>

using namespace std;

const int N=500005;

int n,a,b,ans;
int l=1,r,mid;
int wet[N];

inline int fastestTime()
{
    int ans=0,w;
    for(int i=1;i<=n;++i)
    {
        w=wet[i]-mid*a;
        if(w>0)
        {
            if(w%b==0)
                ans=ans+w/b;
            else
                ans=ans+w/b+1;
        }
    }
    return ans;
}

int main()
{
    scanf("%d%d%d",&n,&a,&b);
    for(int i=1;i<=n;++i)
    {
        scanf("%d",&wet[i]);
        r=max(r,wet[i]/a+1);
    }
    while(l<=r)
    {
        mid=(l+r)/2;
        int tot=fastestTime();
        if(tot<=mid)
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