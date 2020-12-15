#include<bits/stdc++.h>
using namespace std;
int n,m;
int a,b;
int t[500060];
int lowbit(int k)
{
	return k&-k;
}
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
		scanf("%d",&a);
		add(i,a-b);
		b=a;
	}
	for(int i=1;i<=m;i++)
	{
		int o,x,y,k;
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
			printf("%d\n",query(x));
		}
	}
	return 0;
}
