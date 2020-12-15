#include<cstdio>
#include<iostream>
#include<queue>
#include<string>

using namespace std;

const int N=1005;

struct node
{
    int x,y,step;
}p,t;

queue <node> q;

int n,maze[N][N];
int sx,sy,ex,ey;
bool vis[N][N];

int dir[4][2]={1,0,-1,0,0,1,0,-1};

void bfs()
{
    while(!q.empty())
    {
        p=q.front();
        if(p.x==ex && p.y==ey)
        {
            printf("%d\n",p.step);
            return ;
        }
        q.pop();
        for(int i=0;i<4;++i)
        {
            int x=p.x+dir[i][0];
            int y=p.y+dir[i][1];
            if(x>=1 && x<=n && y>=1 && y<=n)
                if(!maze[x][y] && !vis[x][y])
                {
                    vis[x][y]=true;
                    t.x=x;
                    t.y=y;
                    t.step=p.step+1;
                    q.push(t);
                }
        }
    }
}

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j)
        {
            char c;
            cin>>c;
            if(c=='1')
                maze[i][j]=1;
        }
    scanf("%d%d%d%d",&sx,&sy,&ex,&ey);
    p.x=sx;
    p.y=sy;
    p.step=0;
    q.push(p);
    bfs();
    return 0;
}