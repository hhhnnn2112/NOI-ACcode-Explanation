#pragma GCC optimize(3)
#include<cstdio>
#include<algorithm>
#include<cstring>

using namespace std;

const int N=2005,M=2001005;

struct node {
    int x,y,val;
}a[M];

int n,c,tot,ans;
int x[N],y[N],fa[N];

inline int area(int a) {
    return a*a;
}

inline int dist(int xi,int xj,int yi,int yj) {
    return area(xi-xj)+area(yi-yj);
}

inline bool cmp(node a,node b) {
    return a.val<b.val;
}

inline int find(int x) {
    if(fa[x]==x) return x;
    return fa[x]=find(fa[x]);
}

int main() {
    scanf("%d%d",&n,&c);
    for(int i=1;i<=n;++i) {
        scanf("%d%d",&x[i],&y[i]);
        for(int j=1;j<i;++j) {
            int dis=dist(x[i],x[j],y[i],y[j]);
            if(dis>=c) {
                ++tot;
                a[tot].x=i;
                a[tot].y=j;
                a[tot].val=dis;
            }
        }
    }
    sort(a+1,a+tot+1,cmp);
    for(int i=1;i<=n;++i) fa[i]=i;
    int cnt=0;
    for(int i=1;i<=tot;++i) {
        if(cnt==n-1) break;
        int ancx=find(a[i].x),ancy=find(a[i].y);
        if(ancx!=ancy) {
            fa[ancy]=ancx;
            ans+=a[i].val;
            ++cnt;
        }
    }
    if(cnt==n-1) printf("%d\n",ans);
    else printf("-1\n");
    return 0;
}