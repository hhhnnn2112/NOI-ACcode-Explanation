#include<bits/stdc++.h>
using namespace std;
int mps[305][305];
int v[305][305];
int ans[305][305];
int dx[5]={0,0,1,-1,0};
int dy[5]={1,-1,0,0,0};
int m;
queue<int> q1,q2;
bool in(int x,int y)
{
	return ((x>=0)&&(y>=0));
}
int main()
{
	scanf("%d",&m);
	memset(mps,0x3f,sizeof mps);
	for(int i=1;i<=m;i++)
	{
		int t,x,y;
		scanf("%d%d%d",&x,&y,&t);
		for(int i=0;i<=4;i++)
		{
			if(in(x+dx[i],y+dy[i]))
			{
				mps[x+dx[i]][y+dy[i]]=min(mps[x+dx[i]][y+dy[i]],t);
			}
		}
	}
	v[0][0]=1;
	q1.push(0);
	q2.push(0);
	while(q1.size())
	{
		int x=q1.front();
		int y=q2.front();
		q1.pop();q2.pop();
		if(mps[x][y]==0x3f3f3f3f)
		{
			printf("%d",ans[x][y]);
			return 0;
		}
		else
		{
			for(int i=0;i<=3;i++)
			{
				if(in(x+dx[i],y+dy[i])&&ans[x][y]+1<mps[x+dx[i]][y+dy[i]]&&!v[x+dx[i]][y+dy[i]])
				{
					v[x+dx[i]][y+dy[i]]=1;
					ans[x+dx[i]][y+dy[i]]=ans[x][y]+1;
					q1.push(x+dx[i]);
					q2.push(y+dy[i]);
				}
			}
		}
	}
	printf("-1");
	return 0;
}
