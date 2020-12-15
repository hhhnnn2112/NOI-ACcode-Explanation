#include<cstdio>
#include<algorithm>

using namespace std;

const int N=105;

int n,m;
int dp[N][N];

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;++i)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        dp[a][b]=1;
    }
    for(int k=1;k<=n;++k)
        for(int i=1;i<=n;++i)
            for(int j=1;j<=n;++j)
                if(dp[i][k] && dp[k][j])
                    dp[i][j]=1;
    int ans=0;
    for(int i=1;i<=n;++i)
    {
        int cnt=0;
        for(int j=1;j<=n;++j)
            if(i!=j && (dp[i][j] || dp[j][i]))
                ++cnt;
        if(cnt==n-1)
            ++ans;
    }
    printf("%d\n",ans);
    return 0;
}