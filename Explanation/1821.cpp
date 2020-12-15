#include<cstdio>
#include<cstring>
#include<algorithm>

#define ll long long

using namespace std;

const ll N=1005;

ll n,m,x,g[N][N];
ll ans;

int main()
{
    scanf("%lld%lld%lld",&n,&m,&x);
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j)
            g[i][j]=1<<20;
    for(int i=1;i<=m;++i)
    {
        ll u,v,w;
        scanf("%lld%lld%lld",&u,&v,&w);
        g[u][v]=min(w,g[u][v]);
    }
    for(int k=1;k<=n;++k)
        for(int i=1;i<=n;++i)
            for(int j=1;j<=n;++j)
                g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
    for(int i=1;i<=n;++i)
        if(i!=x)
            ans=max(ans,g[i][x]+g[x][i]);
    printf("%lld\n",ans);
}