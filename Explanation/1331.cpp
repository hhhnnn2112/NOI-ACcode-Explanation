#include<cstdio>
#include<iostream>
#include<string>

using namespace std;

const int N=1005;

int r,c;
char maze[N][N];
int ans;
int dir[2][4]={1,0,-1,0,0,1,0,-1};

void dfs(int x,int y)
{
    maze[x][y]='.';
    for(register int i=0;i<4;++i)
    {
        int tx=x+dir[0][i];
        int ty=y+dir[1][i];
        if(tx>=1 && tx<=r && ty>=1 && ty<=c)
            if(maze[tx][ty]=='#')
            {
                maze[tx][ty]='.';
                dfs(tx,ty);
            }
    }
}

int isaship(int x,int y)
{
    int cnt=0;
    if(maze[x][y]=='#')
        ++cnt;
    if(maze[x+1][y]=='#')
        ++cnt;
    if(maze[x][y+1]=='#')
        ++cnt;
    if(maze[x+1][y+1]=='#')
        ++cnt;
    if(cnt==3)
        return 0;
    else
        return 1;
}

int main()
{
    scanf("%d%d",&r,&c);
    for(register int i=1;i<=r;++i)
        for(register int j=1;j<=c;++j)
         cin>>maze[i][j];
    for(register int i=1;i<=r;++i)
        for(register int j=1;j<=c;++j)
            if(i<r && i<c)
                if(!isaship(i,j))
                {
                    printf("Bad placement.\n");
                    return 0;
                }
    for(register int i=1;i<=r;++i)
        for(register int j=1;j<=c;++j)
            if(maze[i][j]=='#')
            {
                ++ans;
                dfs(i,j);
            }
    printf("There are %d ships.\n",ans);
    return 0;
}