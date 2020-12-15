#pragma GCC optimize(3)
#include<cstdio>
#include<algorithm>
typedef long long ll;

using namespace std;

const int N=1000005;

ll n,x,ans;
ll a[N],pre[N],hugnum[N]; //pre记录前缀和

inline int sum(int x) { //等差数列求和
    return (x+1)*x/2;
}

int main()
{
    scanf("%lld%lld",&n,&x);
    for(register int i=1;i<=n;++i) {
        scanf("%lld",&a[i]);
        a[i+n]=a[i]; //链转换为环
    }
    for(register int i=1;i<=2*n;++i) {
        pre[i]=pre[i-1]+a[i]; //记录前缀和
        hugnum[i]=hugnum[i-1]+sum(a[i]); //记录拥抱数量
    }
    for(register int l=1,i=1+n;i<=2*n;++i) {
        while(pre[i]-pre[l]>x) ++l;
        ll nowhug=hugnum[i]-hugnum[l]; //统计当前情况下拥抱数
        ll rel=x-pre[i]+pre[l]; //统计天数
        nowhug+=(a[l]*2-rel+1)*rel/2;
        if(nowhug>ans)
            ans=nowhug;
    }
    printf("%lld\n",ans);
    return 0;
}

/*
1 2 3
4*3/2
*/