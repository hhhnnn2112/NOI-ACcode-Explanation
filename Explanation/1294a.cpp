#include<cstdio>
#include<cstring>

using namespace std;

const int N=25;

int n,m;
int way[N][N],used[N];
int ans;

int max(int a,int b)
{
    if(a>=b)
        return a;
    return b;
}

void dfs(int pos,int dis)
{
    ans=max(ans,dis);
    for(int i=1;i<=n;++i)
        if(!used[i]&&way[pos][i])
        {
            used[i]=1;
            dfs(i,dis+way[pos][i]);
            used[i]=0;
        }
}

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;++i)
    {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        way[a][b]=way[b][a]=c;
    }
    for(int i=1;i<=n;++i)
    {
        memset(used,0,sizeof(used));
        used[i]=1;
        dfs(i,0);
    }
    printf("%d\n",ans);
    return 0;
}