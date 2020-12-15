#include<queue>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define N 100
using namespace std;
char ch;
bool flag,vis[N][N],vist[N][N][5];
int n,m,d,sx,sy,ex,ey,dis[N][N];
int xx[4][3]={{0,0,0},{-1,-2,-3},{0,0,0},{1,2,3}};
int yy[4][3]={{-1,-2,-3},{0,0,0},{1,2,3},{0,0,0}};
int read()
{
    int x=0,f=1; char ch=getchar();
    while(ch<'0'||ch>'9') ch=getchar();
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*f;
}
struct Que
{
    int x,y,d,step;
}que;
queue<Que>q;
int main()
{
    n=read(),m=read();
    for(int i=1;i<=n;i++)
     for(int j=1;j<=m;j++)
     {
         vis[i][j]=read();
          if(vis[i][j])
             vis[i-1][j]=vis[i-1][j-1]=vis[i][j-1]=true;
      } 
    sx=read(),sy=read();
    ex=read(),ey=read();
    cin>>ch;vis[sx][sy]=1;
    if(ch=='W') que.d=0;
    if(ch=='E') que.d=2;
    if(ch=='N') que.d=1;
    if(ch=='S') que.d=3;
    que.x=sx,que.y=sy;
    dis[sx][sy]=que.step=0;
    vist[sx][sy][que.d]=true;
    q.push(que);
    while(!q.empty())
    {
        Que p=q.front();q.pop();
        if(p.x==ex&&p.y==ey){ printf("%d",p.step); return 0;}
        for(int i=0;i<3;i++)
        {
            int x=p.x+xx[p.d][i],y=p.y+yy[p.d][i];
            if(x<1||y<1||x>=n||y>=m||vis[x][y]) break;
            if(vist[x][y][p.d]) continue;
            vist[x][y][p.d]=true;
            que.x=x,que.y=y,que.d=p.d,que.step=p.step+1;
            q.push(que);         
        }        
        que.x=p.x,que.y=p.y,que.d=p.d+1,que.step=p.step+1;
        if(p.d+1==4) que.d=0;
        if(!vist[que.x][que.y][que.d]) vist[que.x][que.y][que.d]=true,q.push(que);
        que.x=p.x,que.y=p.y,que.d=p.d-1,que.step=p.step+1;
        if(p.d-1==-1) que.d=3;
        if(!vist[que.x][que.y][que.d]) 
          vist[p.x][p.y][p.d]=true,q.push(que);
    }
    printf("-1");
    return 0;
}