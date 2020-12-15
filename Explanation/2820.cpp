#include<cstdio>
#include<cstring>

using namespace std;

const int N=105;

int n,kk,ans,cnt;
int g[N][N],vis[N],low[N];
int pos,k=1,mint;

int main()
{
    scanf("%d%d",&n,&kk);
    memset(g,127,sizeof(g));
    for(int i=1;i<=kk;++i)
    {
        int x,y,val;
        scanf("%d%d%d",&x,&y,&val);
        if(val<g[x][y])
            g[x][y]=g[y][x]=val;
        cnt+=val;
    }
    memset(low,127,sizeof(low));
    for(int i=1;i<n;++i)
    {
        pos=k;
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
    }
    printf("%d\n",cnt-ans);
    return 0;
}