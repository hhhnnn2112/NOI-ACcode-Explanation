#include<bits/stdc++.h>
using namespace std;
int a[10][10];
int h[10];
int l[10];
int g[10];
int ans=1e9;
int t;
int get(int x,int y)
{
	if(x>=1&&x<=3)
	{
		if(y>=1&&y<=3)
		{
			return 1;
		}
		if(y>=4&&y<=6)
		{
			return 2;
		}
		if(y>=7&&y<=9)
		{
			return 3;
		}
	}
	if(x>=4&&x<=6)
	{
		if(y>=1&&y<=3)
		{
			return 4;
		}
		if(y>=4&&y<=6)
		{
			return 5;
		}
		if(y>=7&&y<=9)
		{
			return 6;
		}
	}
	if(x>=7&&x<=9)
	{
		if(y>=1&&y<=3)
		{
			return 7;
		}
		if(y>=4&&y<=6)
		{
			return 8;
		}
		if(y>=7&&y<=9)
		{
			return 9;
		}
	}
}
void dfs(int x,int y,int sum)
{
	if(sum>=ans)
	{
		return;
	}
	if(y>9)
	{
		if(++t>=1e7+5e6)
		{
			printf("%d",ans);
			exit(0);
		}
		x++;y=1;
		if(h[x-1]&1)return;
		if(x==4)
		{
			if((g[1]&1)||(g[2]&1)||(g[3]&1))return;
		}
		if(x==7)
		{
			if((g[4]&1)||(g[5]&1)||(g[6]&1))return;
		}
		if(x==10)
		{
			if((g[7]&1)||(g[8]&1)||(g[9]&1))return;
			for(int i=1;i<=9;i++)
			{
				if(l[i]&1)return;
			}
			ans=sum;
			return;
		}
	}
	dfs(x,y+1,sum);
	h[x]++;
	l[y]++;
	g[get(x,y)]++;
	dfs(x,y+1,sum+1);
	h[x]--;
	l[y]--;
	g[get(x,y)]--;
}
int main()
{
	for(int i=1;i<=9;i++)
	{
		for(int j=1;j<=9;j++)
		{
			char ch;
			cin>>ch;
			if(ch=='1')
			{
				a[i][j]=1;
				h[i]++;
				l[j]++;
				g[get(i,j)]++;
			}
		}
	}
	dfs(1,1,0);
	printf("%d",ans);
	return 0;
}
