#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>

using namespace std;

const int N=105;

int n,ans;
int tx,ty,dir[4][2]={1,0,-1,0,0,1,0,-1};
int maze[N][N],used[N][N];

void dfs(int x,int y)
{
    for(int i=0;i<4;++i)
    {
        tx=x+dir[i][0];
        ty=y+dir[i][1];
        if(!maze[tx][ty] && !used[tx][ty] && tx>=1 && tx<=n && ty>=1 && ty<=n)
        {
            used[tx][ty]=1;
            dfs(tx,ty);
        }
    }
}

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j)
            scanf("%d",&maze[i][j]);
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j)
            if(i==1 || j==1 || i==n || j==n)
            {
                if(!used[i][j] && maze[i][j]==0)
                    dfs(i,j);
            }
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j)
            if(maze[i][j]==0 && !used[i][j])
                maze[i][j]=2;
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=n;++j)
            printf("%d ",maze[i][j]);
        printf("\n");
    }
    return 0;
}