#include<cstdio>
#include<queue>
#include<cstring>
#include<cmath>
#include<algorithm>

using namespace std;

const int N=505;
const int dx[]={1,-1,0,0},dy[]={0,0,1,-1};

struct node
{
    int x,y;
}a[N][N],p;

int n,m,maze[N][N],point[N][N],cnt,ans;
int sx,sy;
bool vis[N][N];
int l,r,mid;

inline bool bfs(int x)
{
    queue <node> q;
    int tot=0;
    memset(vis,false,sizeof(vis));
    for(int i=1;i<=m;++i)
        for(int j=1;j<=n;++j)
            if(point[i][j] && !vis[i][j])
            {
                while(!q.empty())
                    q.pop();
                q.push(a[i][j]);
                tot=0;
                vis[i][j]=true;
                while(!q.empty())
                {
                    p=q.front();
                    q.pop();
                    for(int k=0;k<4;++k)
                    {
                        int tx=p.x+dx[k],ty=p.y+dy[k];
                        if(tx<1 || tx>m || ty<1 || ty>n || vis[tx][ty])
                            continue;
                        if(abs(maze[tx][ty]-maze[p.x][p.y])>x)
                            continue;
                        vis[tx][ty]=true;
                        q.push(a[tx][ty]);
                        ++tot;
                    }
                }
                if(!tot)
                    return false;
            }
    return true;
}

int main()
{
    scanf("%d%d",&m,&n);
    for(int i=1;i<=m;++i)
        for(int j=1;j<=n;++j)
        {
            scanf("%d",&maze[i][j]);
            a[i][j].x=i;
            a[i][j].y=j;
            r=max(r,maze[i][j]);
        }
    for(int i=1;i<=m;++i)
        for(int j=1;j<=n;++j)
            scanf("%d",&point[i][j]);
    while(l<=r)
    {
        mid=(l+r)/2;
        if(bfs(mid))
        {
            ans=mid;
            r=mid-1;
        }
        else
            l=mid+1;
    }
    printf("%d\n",ans);
    return 0;
}