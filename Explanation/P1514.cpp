#include<bits/stdc++.h>
using namespace std;
int mp[505][505];
int dx[]={0,1,0,-1,0};
int dy[]={0,0,1,0,-1};
int n=0,m=0;
int v[505][505];
int l[505][505];
int r[505][505];
bool in(int x,int y)
{
	return x>=0&&y>=0&&x<n&&y<m;
}
void dfs(int x,int y)
{
	if(v[x][y])
	{
		return;
	}
	v[x][y]=1;
	if(x==n-1)
	{
		l[x][y]=r[x][y]=y;
	}
	else
	{
		l[x][y]=m;
		r[x][y]=0;
	}
	for(int i=1;i<=4;i++)
	{
		int nx=x+dx[i];
		int ny=y+dy[i];
		if(in(nx,ny)&&mp[nx][ny]<mp[x][y])
		{
			dfs(nx,ny);
			l[x][y]=min(l[x][y],l[nx][ny]);
			r[x][y]=max(r[x][y],r[nx][ny]);
		}
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			scanf("%d",&mp[i][j]);
		}
	}
	for(int j=0;j<m;j++)
	{
		dfs(0,j);
	}
	int cnt=0;
	for(int j=0;j<m;j++)
	{
		if(v[n-1][j])
		{
			cnt++;
		}
	}
	if(cnt<m)
	{
		printf("0\n%d",m-cnt);
		return 0;
	}
	int ans=0;
	for(int left=0,right=0;left<m;left=right+1,ans++)
	{
		for(int i=0;i<m;i++)
		{
			if(l[0][i]<=left)
			{
				right=max(right,r[0][i]);
			}
		}
	}
	printf("1\n%d",ans);
	return 0;
}
