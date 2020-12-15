#include<cstdio>
#include<cstring>

using namespace std;

const int N=305;

int n,m;
int g[N][N];
int k=1,low[N],vis[N],mint;
int ans,tot;

int main()
{
    scanf("%d%d",&n,&m);
    memset(g,127,sizeof(g));
    for(int i=1;i<=m;++i)
    {
        int u,v,c;
        scanf("%d%d%d",&u,&v,&c);
        if(c<g[u][v])
        g[u][v]=g[v][u]=c;
    }
    memset(low,127,sizeof(low));
    for(int i=1;i<n;++i)
    {
        int pos=k;
        vis[pos]=1;
        mint=1<<30;
        for(int j=1;j<=n;++j)
            if(!vis[j])
            {
                if(low[j]>g[pos][j])
                    low[j]=g[pos][j];
                if(mint>low[j])
                {
                    mint=low[j];
                    k=j;
                }
            }
        if(mint>ans)
            ans=mint;
    }
    printf("%d %d\n",n-1,ans);
    return 0;
}