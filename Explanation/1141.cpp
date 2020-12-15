#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>

using namespace std;

const int N=1005;

int m,n;
int tx,ty,startx,starty;
int maze[N][N],dp[N][N],ans;
int dir[4][2]={1,0,-1,0,0,1,0,-1};

void dfs(int x,int y)
{
    if(x<1 || x>n || y<1 || y>n || dp[x][y]>-1)
        return ;
    ++ans;
    dp[x][y]=0;
    for(int i=0;i<4;++i)
    {
        tx=x+dir[i][0];
        ty=y+dir[i][1];
        if(maze[tx][ty]!=maze[x][y])
            dfs(tx,ty);
    }
}

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j)
        {
            char c;
            cin>>c;
            if(c=='1')
                maze[i][j]=1;  
        }
    memset(dp,-1,sizeof(dp));
    for(int q=1;q<=m;++q)
    {
        ans=0;
        scanf("%d%d",&startx,&starty);
        if(dp[startx][starty]!=-1)
        {
            printf("%d\n",dp[startx][starty]);
            continue;
        }
        dfs(startx,starty);
        printf("%d\n",ans);
        for(int i=1;i<=n;++i)
            for(int j=1;j<=n;++j)
                if(dp[i][j]==0)
                    dp[i][j]=ans;
    }
    return 0;
}