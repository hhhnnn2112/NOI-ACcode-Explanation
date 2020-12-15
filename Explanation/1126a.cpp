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
int maze[N][N],vis[N][N][4];
int dir[4][2]={0,1,1,0,0,-1,-1,0},tx,ty;//-1,0,0,1,1,0,0,-1

void bfs()
{
    while(!q.empty())
    {
        p=q.front();
        q.pop();
        vis[t.x][t.y][t.d]=1;

        if(t.x==endx && t.y==endy)//找到答案，输出；结束。
        {
            f=true;
            printf("%d\n",t.cnt);
            return ;
        }
        t=p;//用t代替p
        ++t.cnt;//步数一定会+1

        t.d=(t.d+1)%4;//左转
        if(!vis[t.x][t.y][t.d])
            q.push(t);
        t.d=(t.d+3)%4;//右转
        if(!vis[t.x][t.y][t.d])
            q.push(t);
        t.d=p.d;//方向不变，即前进1-3步
        t.x+=dir[t.d][0];//在方向不变的情况下调整位置
        t.y+=dir[t.d][1];
        if(t.x>=1 && t.x<=n && !vis[t.x][t.y][t.d] && !maze[t.x][t.y])//前进1步
        {
            q.push(t);
            t.x+=dir[t.d][0];
            t.y+=dir[t.d][1];//调整到前进2步
            if(t.x>=1 && t.x<=n && t.y>=1 && t.y<=m && !vis[t.x][t.y][t.d] && !maze[t.x][t.y])//若条件满足，前进2步
            {
                q.push(t);
                t.x+=dir[t.d][0];
                t.y+=dir[t.d][0];//调整到前景3步
                if(t.x>=1 && t.x<=n && t.y>=1 && t.y<=m && !vis[t.x][t.y][t.d] && !maze[t.x][t.y])//若条件满足，前进3步
                    q.push(t);
            }
        }//嵌套式搜索
    }
}

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
		{
            scanf("%d",&maze[i][j]);
			if(maze[i][j])
				maze[i-1][j-1]=maze[i-1][j]=maze[i][j-1]=1;
		}
    scanf("%d%d%d%d %c",&startx,&starty,&endx,&endy,&c);
    p.x=startx;
    p.y=starty;
    p.cnt=0;
    if(c=='W')
        p.d=0;
    if(c=='E')
        p.d=2;
    if(c=='N')
        p.d=1;
    if(c=='S')
        p.d=3;
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