#include<cstdio>
#include<algorithm>

using namespace std;

const int N=305;

int n,m,t;
int dp[N][N];

int main()
{
    scanf("%d%d%d",&n,&m,&t);
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j)
            if(i!=j)
                dp[i][j]=10000000;
    for(int i=1;i<=m;++i)
    {
        int s,e,h;
        scanf("%d%d%d",&s,&e,&h);
        dp[s][e]=min(dp[s][e],h);
    }
    for(int k=1;k<=n;++k)
        for(int i=1;i<=n;++i)
            for(int j=1;j<=n;++j)
                dp[i][j]=min(max(dp[i][k],dp[k][j]),dp[i][j]);
    for(int i=1;i<=t;++i)
    {
        int s,e;
        scanf("%d%d",&s,&e);
        if(dp[s][e]==10000000)
            printf("-1\n");
        else
            printf("%d\n",dp[s][e]);
    }
    return 0;
}