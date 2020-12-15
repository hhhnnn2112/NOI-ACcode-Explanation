#pragma GCC optimize(3)
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>

using namespace std;

const int N=1005,M=10005;

struct node {
    int x,y;
    double val;
}a[N*N/2];

int n,k,x[N],y[N],tot,cnt;
int fa[N];
double f[M];

inline int area(int a) {
    return a*a;
}

inline double dist(int i,int j) {
    return sqrt(area(x[i]-x[j])+area(y[i]-y[j]));
}

inline int Find(int x) {
    if(fa[x]==x)
        return x;
    return fa[x]=Find(fa[x]);
}

inline bool cmp(node a,node b) {
    return a.val<b.val;
}

int main()
{
    scanf("%d%d",&n,&k);
    for(register int i=1;i<=n;++i) scanf("%d%d",&x[i],&y[i]);
    for(register int i=1;i<=n;++i)
        for(register int j=1;j<i;++j) {
            ++tot;
            a[tot].x=i;
            a[tot].y=j;
            a[tot].val=dist(i,j);
        }
    for(register int i=1;i<=n;++i) fa[i]=i;
    sort(a+1,a+tot+1,cmp);
    for(register int i=1;i<=tot;++i) {
        int ancx=Find(a[i].x),ancy=Find(a[i].y);
        if(ancx!=ancy) {
            ++cnt;
            fa[ancy]=ancx;
            f[cnt]=a[i].val;
        }
    }
    printf("%.2lf\n",f[n-k+1]);
    return 0;
}