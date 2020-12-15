#include<cstdio>
#include<cstring>

using namespace std;

const int N=405,MAX=2139062143;

int n,m,ha,la;
int dp[N][N],tx,ty;
int dirx[10]={0,-1,-2,-2,-1,1,2,2,1},diry[10]={0,-2,-1,1,2,2,1,-1,-2};

void dfs(int x,int y,int step)
{
    dp[x][y]=step;
    for(int i=1;i<=8;++i)
    {
        tx=x+dirx[i];
        ty=y+diry[i];
        if(dp[tx][ty]>dp[x][y]+1 && tx>=1 && tx<=n && ty>=1 && ty<=m)
        {
            dp[tx][ty]=dp[x][y]+1;
            dfs(tx,ty,step+1);
        }
    }
}

int main()
{
    memset(dp,MAX,sizeof(dp));
    scanf("%d%d%d%d",&n,&m,&ha,&la);
    dp[ha][la]=0;
    dfs(ha,la,0);
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=m;++j)
            if(dp[i][j]!=MAX)
            {
                if(dp[i][j]==MAX)
                    dp[i][j]=-1;
                printf("%-5d",dp[i][j]);
            }
        printf("\n");
    }
    return 0;
}