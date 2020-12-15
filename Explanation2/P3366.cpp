#include<bits/stdc++.h>
using namespace std;
struct edge
{
	int x,y,z;
}a[200005];
int f[5005];
int find(int k)
{
	if(f[k]==k)
	{
		return k;
	}
	return f[k]=find(f[k]);
}
bool cmp(edge a,edge b)
{
	return a.z<b.z;
}
int n,m;
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		f[i]=i;
	}
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].z);
	}
	sort(a+1,a+1+m,cmp);
	int t=0;
	int ans=0;
	for(int i=1;i<=m;i++)
	{
		int x=find(a[i].x),y=find(a[i].y);
		if(x==y)continue;
		ans+=a[i].z;
		f[x]=y;
		t++;
		if(t==n-1)break;
	}
	if(t==n-1)
	{
		printf("%d",ans);
	}
	else
	{
		printf("orz");
	}
	return 0;
}
