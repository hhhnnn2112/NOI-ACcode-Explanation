#include<bits/stdc++.h>
using namespace std;
int t[500005];
int lowbit(int k)
{
	return k&-k;
} 
int n,m;
void add(int x,int y)
{
	while(x<=n)
	{
		t[x]+=y;
		x+=lowbit(x);
	}
}
int query(int x)
{
	int ans=0;
	while(x>0)
	{
		ans+=t[x];
		x-=lowbit(x);
	}
	return ans;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		int x;
		scanf("%d",&x);
		add(i,x);
	}
	for(int i=1;i<=m;i++)
	{
		int o,x,y;
		scanf("%d%d%d",&o,&x,&y);
		if(o==1)
		{
			add(x,y);
		}
		else
		{
			printf("%d\n",query(y)-query(x-1));
		}
	}
	return 0;
}
