#pragma GCC optimize(3)
#include<cstdio>
#include<map>
#include<cmath>
#include<algorithm>
#include<cstring>
typedef long long ll;

using namespace std;

const int N=200005;

map <ll,ll> m;
ll n,c,a[N],len,ans;

int main()
{
    scanf("%lld%lld",&n,&c);
    for(int i=1;i<=n;++i)
    {
        int t;
        scanf("%d",&t);
        if(!m[t])
        {
            ++len;
            a[len]=t;
        }
        ++m[t];
    }
    /*
    for(int i=1;i<=len;++i)
        printf("In[%d]: %d\n",i,m[i]);
    */
    sort(a+1,a+len+1);
    for(int i=1;i<=len;++i)
    {
        int target=a[i]+c,l=i+1,r=len; //target-a[i]=c 
        while(l<r)
        {
            int mid=(l+r)/2;
            if(a[mid]<target)
                l=mid+1;
            else
                r=mid;
        }
        if(target==a[l])
        {
            //printf(">> %d %d; m[a[l]]: %d ; m[target]: %d\n",target,a[l],m[a[l]],m[target]);
            ans+=m[a[l]]*m[target-c];
        }
    }
    printf("%lld\n",ans);
    return 0;
}