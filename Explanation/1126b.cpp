#include<cstdio>
#include<cstring>
#include<queue>

using namespace std;

const int N=55;

struct node
{
    int x,y,d,cnt;
}p,t;

queue <node> q;
int n,m;
int startx,starty,endx,endy;
char c;
bool f=false;
int maze[N][N],vis[N][N][4],ff[N][N];
int dir[4][2]={-1,0,0,1,1,0,0,-1},tx,ty;

void bfs()
{
    while(!q.empty())
    {
        t=q.front();
        q.pop();

        if(t.x==endx && t.y==endy)
        {
            f=true;
            printf("%d\n",t.cnt);
            return ;
        }

        p.cnt=t.cnt+1;

        p.d=(t.d+1)%4;
        p.x=t.x;
        p.y=t.y;
        if(!vis[p.x][p.y][p.d])
        {
            vis[p.x][p.y][p.d]=1;
            q.push(p);
        }
            
        p.d=(t.d+3)%4;
        p.x=t.x;
        p.y=t.y;
        if(!vis[p.x][p.y][p.d])
        {
            vis[p.x][p.y][p.d]=1;
            q.push(p);
        }
        p.d=t.d;
        p.x+=dir[p.d][0];
        p.y+=dir[p.d][1];
        if(p.x>=1 && p.x<=n && p.y>=1 && p.y<=m && !vis[p.x][p.y][p.d] && !maze[p.x][p.y])
        {
            vis[p.x][p.y][p.d]=1;
            q.push(p);
            p.x+=dir[p.d][0];
            p.y+=dir[p.d][1];
            if(p.x>=1 && p.x<=n && p.y>=1 && p.y<=m && !vis[p.x][p.y][p.d] && !maze[p.x][p.y])
            {
                vis[p.x][p.y][p.d]=1;
                q.push(p);
                p.x+=dir[p.d][0];
                p.y+=dir[p.d][1];
                if(p.x>=1 && p.x<=n && p.y>=1 && p.y<=m && !vis[p.x][p.y][p.d] && !maze[p.x][p.y])
                {
                    vis[p.x][p.y][p.d]=1;
                    q.push(p);
                }
            }
        }
    }
}

int main()
{
    scanf("%d%d",&n,&m);
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
            scanf("%d",&ff[i][j]);
    --m;
    --n;
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
            if(ff[i][j]+ff[i+1][j]+ff[i][j+1]+ff[i+1][j+1]) maze[i][j] = 1;
    /*for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
		{
            scanf("%d",&maze[i][j]);
			if(maze[i][j])
				maze[i-1][j-1]=maze[i-1][j]=maze[i][j-1]=1;
		}*/
    scanf("%d%d%d%d %c",&startx,&starty,&endx,&endy,&c);
    p.x=startx;
    p.y=starty;
    p.cnt=0;
    if(c=='W')
        p.d=3;
    if(c=='E')
        p.d=1;
    if(c=='N')
        p.d=0;
    if(c=='S')
        p.d=2;
    vis[p.x][p.y][p.d]=1;
    q.push(p);
    bfs();
    if(!f)
        printf("-1\n");
    return 0;
}
/*

        p.d=t.d;//直行1步
        tx=t.x+dir[p.d][0];
        ty=t.y+dir[p.d][1];
        if(tx>=1 && tx<=n && ty>=1 && ty<=m)
            if(!maze[tx][ty] && dp[tx][ty][p.d]>dp[t.x][t.y][t.d])
            {
                dp[tx][ty][p.d]=dp[t.x][t.y][t.d];
                p.x=tx;
                p.y=ty;
                p.cnt=t.cnt;
                q.push(p);
            }

        p.d=t.d;//直行2步
        tx=t.x+dir_2steps[p.d][0];
        ty=t.y+dir_2steps[p.d][1];
        if(tx>=1 && tx<=n && ty>=1 && ty<=m)
            if(!maze[tx][ty] && dp[tx][ty][p.d]>dp[t.x][t.y][t.d])
            {
                dp[tx][ty][p.d]=dp[t.x][t.y][t.d];
                p.x=tx;
                p.y=ty;
                p.cnt=t.cnt;
                q.push(p);
            }

        p.d=t.d;//直行3步
        tx=t.x+dir_3steps[p.d][0];
        ty=t.y+dir_3steps[p.d][1];
        if(tx>=1 && tx<=n && ty>=1 && ty<=m)
            if(!maze[tx][ty] && dp[tx][ty][p.d]>dp[t.x][t.y][t.d])
            {
                dp[tx][ty][p.d]=dp[t.x][t.y][t.d];
                p.x=tx;
                p.y=ty;
                p.cnt=t.cnt;
                q.push(p);
            }

        p.d=(t.d+1)%4;//右转
        tx=t.x+dir[p.d][0];
        ty=t.y+dir[p.d][1];
        if(tx>=1 && tx<=n && ty>=1 && ty<=m)
            if(!maze[tx][ty] && dp[tx][ty][p.d]>dp[t.x][t.y][t.d]+1)
            {
                dp[tx][ty][p.d]=dp[t.x][t.y][t.d]+1;
                p.x=tx;
                p.y=ty;
                p.cnt=t.cnt+1;
                q.push(p);
            }

        p.d=(t.d+3)%4;//左转
        tx=t.x+dir[p.d][0];
        ty=t.y+dir[p.d][1];
        if(tx>=1 && tx<=n && ty>=1 && ty<=m)
            if(!maze[tx][ty] && dp[tx][ty][p.d]>dp[t.x][t.y][t.d]+1)
            {
                dp[tx][ty][p.d]=dp[t.x][t.y][t.d]+1;
                p.x=tx;
                p.y=ty;
                p.cnt=t.cnt+1;
                q.push(p);
            }
*/