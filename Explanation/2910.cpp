#include<cstdio>
#include<algorithm>

using namespace std;

const int N=105;

int n,m,ans;
int way[N];
int len[N][N];
int dp[N][N][N];

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;++i)
        scanf("%d",&way[i]);
    for(int k=1;k<=n;++k)
        for(int i=1;i<=n;++i)
            for(int j=1;j<=n;++j)
                dp[i][j][k]=10000000;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j)
            scanf("%d",&dp[i][j][0]);
    for(int k=1;k<=n;++k)
        for(int i=1;i<=n;++i)
            for(int j=1;j<=n;++j)
                dp[i][j][k]=min(dp[i][k][k-1]+dp[k][j][k-1],dp[i][j][k-1]);
    for(int i=1;i<m;++i)
    {
        int a=way[i];
        int b=way[i+1];
        ans+=dp[a][b][n];
    }
    printf("%d\n",ans);
    return 0;
}