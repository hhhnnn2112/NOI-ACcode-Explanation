#include<cstdio>
#include<cstring>

using namespace std;

const int N=105;

int m,n;
int dir[4][2]={-1,0,1,0,0,-1,0,1},dp[N][N];
int tx,ty;
char maze[N][N];//白色0，红色1，黄色2

void dfs(int x,int y,int color,bool changed)
{
    if(x==m && y==m)
        return ;
    for(int i=0;i<4;++i)
    {
        tx=x+dir[i][0];
        ty=y+dir[i][1];
        if(tx>=1 && tx<=m && ty>=1 && ty<=m) {
            if (maze[tx][ty] == color) {
                if (dp[tx][ty] > dp[x][y]) {
                    dp[tx][ty] = dp[x][y];
                    dfs(tx, ty, maze[tx][ty], false);
                }
            } else if (maze[tx][ty]) {
                if (dp[tx][ty] > dp[x][y] + 1) {
                    dp[tx][ty] = dp[x][y] + 1;
                    dfs(tx, ty, maze[tx][ty], false);
                }
            } else {
                if (!changed) {
                    if (dp[tx][ty] > dp[x][y] + 2) {
                        dp[tx][ty] = dp[x][y] + 2;
                        dfs(tx, ty, color, true);
                    }
                }
            }
        }
    }
}

int main()
{
    scanf("%d%d",&m,&n);
    for(int i=1;i<=n;++i)
    {
        int px,py,color;
        scanf("%d%d%d",&px,&py,&color);
        maze[px][py]=color+1;
    }
    memset(dp,127,sizeof(dp));
    dp[1][1]=0;
    dfs(1,1,maze[1][1],false);
    if(dp[m][m] > (1<<30))
        printf("-1\n");
    else
        printf("%d\n",dp[m][m]);
    return 0;
}