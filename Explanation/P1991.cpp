#include<bits/stdc++.h>
using namespace std;
int n,s;
int cnt;
struct node
{
	int x,y,bj;
}a[505];
struct edge
{
	int x,y,bj;
	double val;
}b[505*250];
int f[505];
int find(int k)
{
	if(k==f[k])return k;
	return f[k]=find(f[k]);
}
double get(node a,node b)
{
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
bool cmp(edge a,edge b)
{
	return a.val<b.val;
}
int main()
{
	scanf("%d%d",&s,&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&a[i].x,&a[i].y);
		a[i].bj=i;
		for(int j=1;j<i;j++)
		{
			b[++cnt].bj=cnt;
			b[cnt].x=i;
			b[cnt].y=j;
			b[cnt].val=get(a[i],a[j]);
		}
	}
	sort(b+1,b+1+cnt,cmp);
	for(int i=1;i<=n;i++)
	{
		f[i]=i;
	}
	int e=0;
	for(int i=1;i<=cnt;i++)
	{
		if(find(b[i].x)!=find(b[i].y))
		{
			e++;
			f[find(b[i].x)]=find(b[i].y);
			if(e==n-s)
			{
				printf("%.2lf",b[i].val);
				return 0;
			}
		}
	}
	return 0;
}
