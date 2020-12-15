#include<cstdio>
#include<algorithm>
#include<cstring>
typedef unsigned long long ll;

const int N=200005,MOD=998244353;

using namespace std;

ll n,a[N],num[N*2],ans;

int main()
{
    scanf("%lld",&n);
    for(int i=1;i<=n;++i)
        scanf("%lld",&a[i]);
    sort(a+1,a+n+1);
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j)
            if(a[j]<=i)
                ++num[i];
    for(int i=1;i<=a[n];++i)
        printf("Num[%d]: %lld ;\n",i,num[i]);
    for(int i=1;i<n;++i)
        for(int j=i+1;j<=n;++j)
            if(a[i]==a[j])
            {
                ans=(ans+num[a[i]*2-1]%MOD)%MOD;
                /*
                for(int k=1;k<=a[i]*2-1;++k)
                    ans=(ans+num[k]%MOD)%MOD;
                */
            }
    printf("%lld\n",ans);
    return 0;
}