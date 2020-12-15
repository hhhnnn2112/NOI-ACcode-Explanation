#include<cstdio>
#include<iostream>
#include<queue>

using namespace std;

const int N=2005;

struct node
{
	int x,y;
}p,t;

int n,m,shortestPath,sx,sy,dis[N][N];
int dirx[4]={1,-1,0,0},diry[4]={0,0,1,-1};
queue <node> q;
char maze[N][N];
bool vis[N][N];

int bfs()
{
	while(!q.empty())
	{
		p=q.front();
		q.pop();
		int x=p.x;
		int y=p.y;
		if(maze[x][y]=='m')
			return dis[x][y];
		for(int i=0;i<4;++i)
		{
			int tx=x+dirx[i];
			int ty=y+diry[i];
			if(tx<=0 || tx>n || ty<=0 || ty>m || maze[tx][ty]=='#' || vis[tx][ty])
				continue;
			dis[tx][ty]=dis[x][y]+1;
			vis[tx][ty]=true;
			t.x=tx;
			t.y=ty;
			q.push(t);
		}
	}
	return -1;
}

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
            cin>>maze[i][j];
	for(int i=1;i=n;++i)
		for(int j=1;j<=m;++j)
			if(maze[i][j]=='d')
			{
				t.x=i;
				t.y=j;
				break;
			}
	q.push(t);
	vis[t.x][t.y]=true;
	shortestPath=bfs();
	if(shortestPath==-1)
		printf("No Way!\n");
	else
		printf("%d\n",shortestPath);
    return 0;
}