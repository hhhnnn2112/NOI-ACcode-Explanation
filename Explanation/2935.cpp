#include<cstdio>
#include<algorithm>

using namespace std;

const int N=505;

int p,f,c;
int way[N];
int dp[N][N];

int main()
{
    scanf("%d%d%d",&p,&f,&c);
    for(int i=1;i<=f;++i)
        scanf("%d",&way[i]);
    for(int i=1;i<=p;++i)
        for(int j=1;j<=p;++j)
            if(i!=j)
                dp[i][j]=10000000;
    for(int i=1;i<=c;++i)
    {
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        dp[u][v]=dp[v][u]=min(dp[u][v],w);
    }
    for(int k=1;k<=p;++k)
        for(int i=1;i<=p;++i)
            for(int j=1;j<=p;++j)
                dp[i][j]=min(dp[i][k]+dp[k][j],dp[i][j]);
    int ans,mini=1<<30;
    for(int i=1;i<=p;++i)
    {
        int totlen=0;
        for(int j=1;j<=f;++j)
        {
            totlen+=dp[i][way[j]];
        }
        //printf("%d> %d\n",i,totlen);
        if(totlen<mini)
        {
            mini=totlen;
            ans=i;
        }
    }
    printf("%d\n",ans);
    return 0;
}