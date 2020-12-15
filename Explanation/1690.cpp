#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>

using namespace std;

const int N=105,M=15;

int n;
int g[N][N],t,p[M];
int ans=1<<30,sum;
bool vis[N];

void dfs(int pos,int cnt)
{
    if(cnt==0)
    {
        ans=min(ans,sum+g[pos][n]);
        return ;
    }
    for(int i=1;i<=t;i++)
        if(!vis[i])
        {
            vis[i]=true;
            sum+=g[pos][p[i]];
            dfs(p[i],cnt-1);
            vis[i]=false;
            sum-=g[pos][p[i]];
        }
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j)
            scanf("%d",&g[i][j]);
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
        scanf("%d",&p[i]);
    sort(p+1,p+t+1);
    for(int k=1;k<=n;++k)
        for(int i=1;i<=n;++i)
            for(int j=1;j<=n;++j)
                g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
    dfs(1,t);
    printf("%d\n",ans);
    return 0;
}