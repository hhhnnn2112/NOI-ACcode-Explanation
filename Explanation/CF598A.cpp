#include<cstdio>
#include<cmath>
typedef long long ll;

using namespace std;

ll T,n;

int main() {
    scanf("%lld",&T);
    while(T--) {
        scanf("%lld",&n);
        ll ans=n*(n+1)/2;
        int Log=log(n)/log(2)+1e-10;
        ll Ans=(1<<(Log+1))-1;
        ans-=(Ans<<1);
        printf("%lld\n",ans);
    }
    return 0;
}