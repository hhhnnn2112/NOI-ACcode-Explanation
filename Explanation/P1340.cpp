#include<bits/stdc++.h>
using namespace std;
struct edge
{
	int x,y,z,t;
}a[6005];
int f[205];
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
int n,w;
void kr(int time)
{
	int k=0,ans=0;
	for(int i=1;i<=n;i++)
	{
		f[i]=i;
	}
	for(int i=1;i<=w;i++)
	{
		if(find(a[i].x)!=find(a[i].y)&&a[i].t<=time)
		{
			k++;
			ans+=a[i].z;
			f[find(a[i].x)]=find(a[i].y);
		}
		if(k==n-1)
		{
			printf("%d\n",ans);
			return;
		}
	}
	printf("-1\n");
	return;
}
int main()
{
	scanf("%d%d",&n,&w);
	for(int i=1;i<=w;i++)
	{
		scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].z);
		a[i].t=i;
	}
	sort(a+1,a+1+w,cmp);
	for(int i=1;i<=w;i++)
	{
		kr(i);
	}
	return 0;
}
