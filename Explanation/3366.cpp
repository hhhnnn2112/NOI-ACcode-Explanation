#include<cstdio>
#include<cstring>

using namespace std;

const int N=5005;

int n,m,ans;
int g[N][N],low[N],vis[N];
int k=1,mint;

int main()
{
    scanf("%d%d",&n,&m);
    memset(g,127,sizeof(g));
    for(int i=1;i<=m;++i)
    {
        int x,y,val;
        scanf("%d%d%d",&x,&y,&val);
        if(val<g[x][y])
            g[x][y]=g[y][x]=val;
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
        ans+=mint;
        if(ans>(1<<30))
            break;
    }
    if(ans>(1<<30))
        printf("-1\n");
    else
        printf("%d\n",ans);
    return 0;
}