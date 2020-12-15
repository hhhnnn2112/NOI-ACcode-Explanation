#include<cstdio>
#include<iostream>
#include<stack>
#include<cstring>
#include<string>

using namespace std;

const int N=115,M=80;

struct node
{
    int x,y;
}FatherOf[N][M];

stack <int> posx,posy;
int m,n;
int maze[N][M],dp[N][M];
int dir[4][2]={1,0,-1,0,0,1,0,-1},tx,ty;

void dfs(int x,int y)
{
    if(x==n && y==m)
        return ;
    for(int i=0;i<4;++i)
    {
        tx=x+dir[i][0];
        ty=y+dir[i][1];
        if(tx>=1 && tx<=n && ty>=1 && ty<=m)
            if(!maze[tx][ty] && dp[tx][ty]>dp[x][y]+1)
            {
                dp[tx][ty]=dp[x][y]+1;
                FatherOf[tx][ty].x=x;
                FatherOf[tx][ty].y=y;
                dfs(tx,ty);
            }
    }
}

void FindPath(int x,int y)
{
    if(x==1 && y==1)
        return ;
    posx.push(FatherOf[x][y].x);
    posy.push(FatherOf[x][y].y);
    FindPath(FatherOf[x][y].x,FatherOf[x][y].y);
}

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
        {
            char c;
            cin>>c;
            if(c=='*')
                maze[i][j]=1;
        }
    memset(dp,127,sizeof(dp));
    dp[1][1]=0;
    dfs(1,1);
    posx.push(n);
    posy.push(m);
    FindPath(n,m);
    while(!posx.empty())
    {
        printf("%d %d\n",posx.top(),posy.top());
        posx.pop();
        posy.pop();
    }
    return 0;
}