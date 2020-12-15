#include<cstdio>
#include<algorithm>
#include<cstring>

using namespace std;

const int N=55;

int n,m;
int road[N][N],walked[N],a,b,dis;
int tot,ans;

void dfs(int pos,int dis)
{
    ans=max(ans,dis);
    for(int i=1;i<=n;++i)
        if(road[pos][i]&&!walked[i])
        {
            walked[i]=1;
            dfs(i,dis+road[pos][i]);
            walked[i]=0;
        }
}

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;++i)
    {
        scanf("%d%d%d", &a, &b, &dis);
        road[a][b]=road[b][a]=dis;
    }
    for(int i=1;i<=m;++i)
    {
        memset(walked,0,sizeof(walked));
        walked[i]=1;
        dfs(i,0);
        tot=max(tot,ans);
    }
    printf("%d\n",tot);
    return 0;
}