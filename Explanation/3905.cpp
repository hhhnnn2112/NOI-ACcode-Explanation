#include<cstdio>
#include<algorithm>
#include<cstring>

using namespace std;

const int N=105;

int n,m,d;
int g[N][N],h[N][N];

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j)
            h[i][j]=1<<29;
    for(int i=1;i<=m;++i)
    {
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        g[u][v]=g[v][u]=w;
        h[u][v]=h[v][u]=0;
    }
    scanf("%d",&d);
    for(int i=1;i<=d;++i)
    {
        int s,e;
        scanf("%d%d",&s,&e);
        h[s][e]=h[e][s]=g[s][e];
    }
    for(int k=1;k<=n;++k)
        for(int i=1;i<=n;++i)
            for(int j=1;j<=n;++j)
                h[i][j]=min(h[i][j],h[i][k]+h[k][j]);
    int s,e;
    scanf("%d%d",&s,&e);
    printf("%d\n",h[s][e]);
    return 0;
}