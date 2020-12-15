#include<cstdio>
#include<algorithm>
#include<cstring>

using namespace std;

const int N=1000005;

int n,m,tot[N],d[N],s[N],t[N];
int l=1,r,mid;

inline bool check(int x) {
    int room[N],rent[N];
    memset(room,0,sizeof(room));
    memset(rent,0,sizeof(rent));
    for(int i=1;i<=x;++i) {
        room[s[i]]+=d[i];
        room[t[i]+1]-=d[i];
    }
    for(int i=1;i<=n;++i) {
        rent[i]=rent[i-1]+room[i];
        if(rent[i]>tot[i])
            return 0;
    }
    return 1;
}

int main() {
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i) scanf("%d",&tot[i]);
    for(int i=1;i<=m;++i) scanf("%d%d%d",&d[i],&s[i],&t[i]);
    if(check(m)) {
        printf("0\n");
        return 0;
    }
    r=m;
    while(l<r) {
        mid=(l+r)/2;
        if(check(mid))
            l=mid+1;
        else
            r=mid;
    }
    printf("-1\n%d\n",l);
    return 0;
}