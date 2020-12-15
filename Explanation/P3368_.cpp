#include<bits/stdc++.h>
using namespace std;
int tree[500500];
int lowbit(int x)
{
	return x&-x;
}
int n;
void add(int x,int v)
{
	while(x<=n)
	{
		tree[x]+=v;
		x+=lowbit(x);
	}
}
int que(int x)
{
	int res=0;
	while(x>0)
	{
		res+=tree[x];
		x-=lowbit(x);
	}
	return res;
}
int m;
int x,y;
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&x);
		add(i,x-y);
		y=x;
	}
	for(int i=1;i<=m;i++)
	{
		int o,k;
		scanf("%d",&o);
		if(o==1)
		{
			scanf("%d%d%d",&x,&y,&k);
			add(x,k);
			add(y+1,-k);
		}
		else
		{
			scanf("%d",&x);
			printf("%d\n",que(x));
		}
	}
	return 0;
}
