#include<cstdio>
#include<cmath>
#include<map>
typedef long long ll;

using namespace std;

ll p,b,n,power,k,cur=1;

map<ll,ll> m;

inline ll read() {
    ll x=0,w=1;
    char ch=0;
    while(ch<'0' || ch>'9') {
        if(ch=='-')
            w=-1;
        ch=getchar();
    }
    while(ch>='0' && ch<='9') {
        x=x*10+(ch-'0');
        ch=getchar();
    }
    return x*w;
}

int main() {
    p=read(),b=read(),n=read();
    b%=p,n%=p,power=n,k=sqrt(p)+1;
    if(n==1) {
        printf(0);
        return 0;
    }
    for(int i=0;i<k;++i) {
        m[power]=i;
        power=(power*b)%p;
    }
    power=1;
    for(int i=1;i<=k;++i)
        cur=(cur*b)%p;
    for(int i=1;i<=k+1;++i) {
        power=(power*cur)%p;
        if(m[power]) {
            printf("%lld\n",i*k-m[power]);
            return 0;
        }
    }
    printf("no solution\n");
}