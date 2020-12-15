#pragma GCC optimize(3)
#include<cstdio>

using namespace std;

long long n,x1,x2,y1,y2;

int main() {
    scanf("%lld",&n);
    for(int i=1;i<=n;++i) {
        scanf("%lld%lld%lld%lld",&x1,&x2,&y1,&y2);
        printf("%lld\n",(y1-x1)*(y2-x2)+1);
    }
    return 0;
}