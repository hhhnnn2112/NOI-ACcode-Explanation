#include<cstdio>
#include<algorithm>
#include<cstdio>
typedef long long ll;

using namespace std;

const int N=20005;

struct node {
    ll x,y,v1,v2;
}a[N];

ll n,k,m,fa[N];

inline bool cmp1(node a,node b) {
    return a.v1<b.v1;
}

inline int find(int x) {
    if(fa[x]==x)
        return x;
    return fa[x]=find(fa[x]);
}

int main() {
    scanf("%lld%lld%lld",&n,&k,&m);
    --m;
    for(register int i=1;i<=m;++i)
        scanf("%lld%lld%lld%lld",&a[i].x,&a[i].y,&a[i].v1,&a[i].v2);
    sort(a+1,a+m+1,cmp1);
    return 0;
}