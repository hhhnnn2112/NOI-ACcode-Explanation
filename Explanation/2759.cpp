#include<cstdio>
#include<cmath> //log10
typedef long long ll;

using namespace std;

const ll N=2000000000;

ll n;
ll l,r=N,mid;

inline ll calcBits() {
    return ll(mid*log10(1.0*mid))+1;
}

int main() {
    scanf("%lld",&n);
    while(l<r) { //二分查找
        mid=(l+r)/2;
        ll bits=calcBits();
        if(bits<n)
            l=mid+1;
        else
            r=mid;
    }
    printf("%lld\n",l);
    return 0;
}