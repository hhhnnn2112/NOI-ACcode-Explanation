#include<cstdio>
#include<algorithm>
#include<cstring>

using namespace std;

const int N=100005;

struct node
{
    int u,v,w;
}a[N];

int n,m,k,fa[N],cnt,ans;

inline bool cmp(node a,node b)
{
    return a.w>b.w;
}

inline int find(int x)
{
    if(fa[x]==x)
        return x;
    return fa[x]=find(fa[x]);
}

int main()
{
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=m;++i)
        scanf("%d%d%d",&a[i].u,&a[i].v,&a[i].w);
    sort(a+1,a+m+1,cmp);
    for(int i=1;i<=n;++i)
        fa[i]=i;
    for(int i=1;i<=m;++i)
    {
        int ancx=find(a[i].u),ancy=find(a[i].v);
        if(ancx!=ancy)
        {
            fa[ancy]=ancx;
            ++cnt;
            ans+=a[i].w;
        }
        if(cnt==k)
            break;
    }
    printf("%d\n",ans);
    return 0;
}