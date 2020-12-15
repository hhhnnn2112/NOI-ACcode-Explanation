#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>

using namespace std;

const int N=305;

int n,a,b,c,ans=1<<30;
int maze[N][N],vis[N][N];
int dir[4][2]={1,0,-1,0,0,1,0,-1};

void dfs(int x,int y,int step)
{
    if(step>ans || (maze[x][y]!=-1 && step>=maze[x][y]) || (vis[x][y] && vis[x][y]<=step))
        return ;
    vis[x][y]=step;
    if(maze[x][y]==-1)
    {
        ans=step;
        return ;
    }
    for(int i=0;i<4;++i)
        if(x+dir[i][0]>=0 && y+dir[i][1]>=0)
            dfs(x+dir[i][0],y+dir[i][1],step+1);
}
int main()
{
    memset(maze,-1,sizeof(maze));
    scanf("%d",&n);
    for(int i=1;i<=n;++i)
    {
        scanf("%d%d%d",&a,&b,&c);
        if(maze[a][b]>c || maze[a][b]==-1)
            maze[a][b]=c;
        for(int j=0;j<4;++j)
        {
            int x=a+dir[j][0],y=b+dir[j][1];
            if(x>=0 && y>=0)
                if(maze[x][y]>c || maze[x][y]==-1)
                    maze[x][y]=c;
        }
    }
    dfs(0,0,0);
    if(ans==(1<<30))
        printf("-1\n");
    else
        printf("%d\n",ans);
    return 0;
}