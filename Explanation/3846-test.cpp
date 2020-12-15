#include<cstdio>
#include<cmath>
#include<map>
typedef long long ll;

using namespace std;

ll a,b,c,power,p,qp=1;

map<ll,ll> m;

int main() {
    scanf("%lld%lld%lld",&c,&a,&b);
    a%=c,b%=c,power=b,p=sqrt(c)+1;
    if(b==1) {
        printf(0);
        return 0;
    }
    for(int i=0;i<p;++i) {
        m[power]=i;
        power=(power*a)%c;
    }
    power=1;
    for(int i=1;i<=p;++i)
        qp=(qp*a)%c;
    for(int i=1;i<=p+1;++i) {
        power=(power*qp)%c;
        if(m[power]) {
            printf("%lld\n",i*p-m[power]);
            return 0;
        }
    }
    printf("no solution\n");
}