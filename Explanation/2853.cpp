#include<cstdio>

using namespace std;

const int N=1005;

int k,n,m,ans,now;
int maze[N][N],pos[N];
int vis[N][N];

void dfs(int pos)
{
    for(int i=1;i<=n;++i)
        if(!vis[now][i] && maze[pos][i])
        {
            vis[now][i]=1;
            dfs(i);
        }
}

int main()
{
    scanf("%d%d%d",&k,&n,&m);
    for(register int i=1;i<=k;++i)
    {
        int t;
        scanf("%d",&t);
        pos[t]=1;
    }
    for(register int i=1;i<=m;++i)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        maze[u][v]=1;
    }
    for(int i=1;i<=n;++i)
        if(pos[i])
        {
            now=i;
            vis[i][i]=1;
            dfs(i);
        }
    for(int i=1;i<=n;++i)
    {
        bool f=true;
        for(int j=1;j<=n;++j)
            if(!vis[j][i] && pos[j])
                f=false;
        if(f)
            ++ans;
    }
    printf("%d\n",ans);
    return 0;
}