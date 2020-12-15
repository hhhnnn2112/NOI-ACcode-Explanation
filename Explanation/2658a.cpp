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
    int tot=1;
    queue <node> q;
    memset(vis,false,sizeof(vis));
    vis[sx][sy]=true;
    q.push(a[sx][sy]);
    while(!q.empty())
    {
        p=q.front();
        q.pop();
        for(int i=0;i<4;++i)
        {
            int tx=p.x+dx[i],ty=p.y+dy[i];
            if(tx<1 || tx>m || ty<1 || ty>n || vis[tx][ty])
                continue;
            if(abs(point[p.x][p.y]-point[tx][ty])>x)
                continue;
            vis[tx][ty]=true;
            q.push(a[tx][ty]);
            if(point[tx][ty])
                ++tot;
            if(tot==cnt)
                return true;
        }
    }
    return false;
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