#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>

using namespace std;

const int N=1005,M=505;

struct node {
    int x,y;
    double val;
}a[N*N/2];

int n,m,jump[M],treex[N],treey[N],cnt,tot,ans;
double maxx;
int fa[N*N/2];

inline int area(int a) {
    return a*a;
}

inline double dist(int i,int j) {
    return sqrt(area(treex[i]-treex[j])+area(treey[i]-treey[j]));
}

inline bool cmp(node a,node b) {
    return a.val<b.val;
}

inline int find(int x) {
    if(fa[x]==x)
        return x;
    return fa[x]=find(fa[x]);
}

int main() {
    scanf("%d",&m);
    for(int i=1;i<=m;++i) scanf("%d",&jump[i]);
    scanf("%d",&n);
    for(int i=1;i<=n;++i) scanf("%d%d",&treex[i],&treey[i]);
    for(int i=1;i<=n;++i)
        for(int j=1;j<i;++j) {
            ++cnt;
            a[cnt].x=i;
            a[cnt].y=j;
            a[cnt].val=dist(i,j);
        }
    sort(a+1,a+cnt+1,cmp);
    for(int i=1;i<=n;++i) fa[i]=i;
    for(int i=1;i<=cnt;++i) {
        if(tot==n-1)
            break;
        int ancx=find(a[i].x),ancy=find(a[i].y);
        if(ancx!=ancy) {
            ++tot;
            fa[ancy]=ancx;
            maxx=max(a[i].val,maxx);
        }
    }
    for(int i=1;i<=m;++i)
        if(double(jump[i])>=maxx)
            ++ans;
    printf("%d\n",ans);
    return 0;
}