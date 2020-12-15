#include<cstdio>
#include<algorithm>
#include<cstring>
#define lowbit(x) (x&(-x))
typedef long long ll;

using namespace std;

const int N=500005;

struct node {
    ll num,id;
}a[N];

ll n,c[N],ans;

inline bool cmp(node a,node b) {
    if(a.num!=b.num)
        return a.num<b.num;
    else
        return a.id<b.id;
}

inline void Update(ll id,ll k) {
    while(id<=n) {
        c[id]+=k;
        id+=lowbit(id);
    }
    return ;
}

inline ll Query(ll id) {
    ll ans=0;
    while(id>0) {
        ans+=c[id];
        id-=lowbit(id);
    }
    return ans;
}

int main() {
    scanf("%lld",&n);
    for(int i=1;i<=n;++i) {
        scanf("%lld",&a[i].num);
        a[i].id=i;
    }
    sort(a+1,a+n+1,cmp);
    for(int i=1;i<=n;++i) {
        ans+=Query(a[i].id);
        Update(a[i].id,1);
    }
    printf("%lld\n",n*(n-1)/2-ans);
    return 0;
}