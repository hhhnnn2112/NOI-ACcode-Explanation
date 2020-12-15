#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>

using namespace std;

const int N=105;

int w,h,ans;
int tx,ty,dir[4][2]={1,0,-1,0,0,1,0,-1};
char maze[N][N];

void dfs(int x,int y)
{
    for(int i=0;i<4;++i)
    {
        tx=x+dir[i][0];
        ty=y+dir[i][1];
        if(maze[tx][ty]!='0' && tx>=0 && tx<w && ty>=0 && ty<h)
        {
            maze[tx][ty]='0';
            dfs(tx,ty);
        }
    }
}

int main()
{
    scanf("%d%d",&w,&h);
    for(int i=0;i<w;++i)
        for(int j=0;j<h;++j)
            cin>>maze[i][j];
    for(int i=0;i<w;++i)
        for(int j=0;j<h;++j)
        {
            if(maze[i][j]!='0')
            {
                dfs(i,j);
                ++ans;
            }
        }
    printf("%d\n",ans);
    return 0;
}