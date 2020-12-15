#include<cstdio>
#include<algorithm>

using namespace std;

const int N=105;

int n,m;
int dp[N][N],dis[N][N];

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j)
            if(i!=j)
                dp[i][j]=dis[i][j]=(1<<29);
    for(int i=1;i<=m;++i)
    {
        int u,v,d;
        scanf("%d%d%d",&u,&v,&d);
        dp[u][v]=dp[v][u]=dis[u][v]=dis[v][u]=min(dis[v][u],d);
    }
    int ans=(1<<29);
    for(int k=1;k<=n;++k)
    {
        for(int i=1;i<k;++i)
            for(int j=i+1;j<k;++j)
                ans=min(ans,dis[k][i]+dis[k][j]+dp[i][j]);
        for(int i=1;i<=n;++i)
            for(int j=1;j<=n;++j)
                dp[i][j]=dp[j][i]=min(dp[i][k]+dp[k][j],dp[i][j]);
    }
    if(ans!=(1<<29))
        printf("%d\n",ans);
    else
        printf("No solution.\n");
    return 0;
}