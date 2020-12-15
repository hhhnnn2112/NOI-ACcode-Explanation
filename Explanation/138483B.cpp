#include<cstdio>
#include<algorithm>
#include<cstring>
typedef long long ll;

using namespace std;

const int N=200005,MOD=998244353;

ll n,a[N],ans;

inline bool check(int i,int j,int k)
{
    if(a[i]+a[j]>a[k] && a[i]+a[k]>a[j] && a[j]+a[k]>a[i] && (a[i]==a[j] || a[i]==a[k] || a[j]==a[k]))
        return true;
    else
        return false;
}

int main()
{
    scanf("%lld",&n);
    for(int i=1;i<=n;++i)
        scanf("%lld",&a[i]);
    sort(a+1,a+n+1);
    for(int i=1;i<=n-2;++i)
        for(int j=i+1;j<=n-1;++j)
            for(int k=j+1;k<=n;++k)
                if(check(i,j,k))
                    ans=(ans+1)%MOD;
    printf("%lld\n",ans);
    return 0;
}