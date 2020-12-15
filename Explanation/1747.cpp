#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>

using namespace std;

const int N=25;

int posx,posy;
int tx,ty,dirx[12]={-2,-2,-1,-1,2,2,1,1,-2,-2,2,2},diry[12]={-1,1,2,-2,1,-1,2,-2,-2,2,-2,2};
int dp[N][N];

void dfs(int x,int y,int step)
{
    dp[x][y]=step;
    for(int i=0;i<12;++i)
    {
        tx=x+dirx[i];
        ty=y+diry[i];
        if((dp[tx][ty]>step+1 || dp[tx][ty]==0) && tx>=1 && tx<=20 && ty>=1 && ty<=20)
        {
            dfs(tx,ty,step+1);
        }
    }
}

int main()
{
    for(int q=1;q<=2;++q)
    {
        memset(dp,0,sizeof(dp));
        scanf("%d%d",&posx,&posy);
        dfs(posx,posy,0);
        printf("%d\n",dp[1][1]);
    }
    return 0;
}