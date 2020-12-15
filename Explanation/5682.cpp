#include<cstdio>
#include<cstring>
#include<algorithm>

typedef long long ll;

using namespace std;

const ll N=200005;

ll n,a[N],cnt;
ll s[N];
bool f[N];

bool cmp(ll a,ll b)
{
    return a>b;
}

int main()
{
    scanf("%lld",&n);
    for(int i=1;i<=n;++i)
        scanf("%lld",&a[i]);
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j)
            if(i!=j)
            {
                ll mod=a[i]%a[j];
                if(!f[mod])
                {
                    f[mod]=true;
                    ++cnt;
                    s[cnt]=mod;
                }
            }
    if(cnt<2)
    {
        printf("-1\n");
        return 0;
    }
    sort(s+1,s+cnt+1,cmp);
    printf("%lld\n",s[2]);
    return 0;
}