#pragma GCC optimize(3)
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>

using namespace std;

const int N=305,M=45305;

struct node {
    int x,y,val;
}a[M];

int n,tot,ans,fa[M];

inline bool cmp(node a,node b) {
    return a.val<b.val;
}

inline int find(int x) {
    if(fa[x]==x)
        return x;
    return fa[x]=find(fa[x]);
}

int main() {
    scanf("%d",&n);
    for(int i=1;i<=n;++i) {
        int k;
        scanf("%d",&k);
        ++tot;
        a[tot].x=0;
        a[tot].y=i;
        a[tot].val=k;
    }
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j) {
            int k;
            scanf("%d",&k);
            if(i>j) {
                ++tot;
                a[tot].x=i;
                a[tot].y=j;
                a[tot].val=k;
            }
        }
    sort(a+1,a+tot+1,cmp);
    for(int i=0;i<=tot;++i)
        fa[i]=i;
    int cnt=0;
    for(int i=1;i<=tot;++i) {
        if(cnt==n)
            break;
        int ancx=find(a[i].x),ancy=find(a[i].y);
        if(ancx!=ancy) {
            fa[ancy]=ancx;
            ans+=a[i].val;
            ++cnt;
        }
    }
    printf("%d\n",ans);
    return 0;
}