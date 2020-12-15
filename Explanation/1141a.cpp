#include<cstdio>
#include<iostream>
#include<string>
#include<queue>
#include<cstring>

using namespace std;

const int N=1005,M=100005;

struct node
{
    int x,y;
}p,t;

queue <node> q;
int n,m,cnt;
int maze[N][N],used[N][N],ans[M];
int startx,starty,tx,ty;
int dir[4][2]={1,0,-1,0,0,1,0,-1};

void bfs(int k)
{
    while(!q.empty())
    {
        t=q.front();
        q.pop();
        ++cnt;
        for(int i=0;i<4;++i)
        {
            tx=t.x+dir[i][0];
            ty=t.y+dir[i][1];
            if(tx>=1 && tx<=n && ty>=1 && ty<=n)
                if(maze[t.x][t.y]!=maze[tx][ty] && !used[tx][ty])
                {
                    used[tx][ty]=k;
                    p.x=tx;
                    p.y=ty;
                    q.push(p);
                }
        }
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
    for(int que=1;que<=m;++que)
    {
        cnt=0;
        scanf("%d%d",&startx,&starty);
        if(!used[startx][starty])
        {
            p.x=startx;
            p.y=starty;
            used[p.x][p.y]=que;
            q.push(p);
            bfs(que);
            ans[que]=cnt;
            printf("%d\n",cnt);
        }
        else
        {
            printf("%d\n",ans[used[startx][starty]]);
        }
    }
    return 0;
}