#include<bits/stdc++.h>
using namespace std;
int f[200005];
int find(int k)
{
	if(f[k]==k)return k;
	return f[k]=find(f[k]);
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
		int x,y,z;
		scanf("%d%d%d",&z,&x,&y);
		int fx=find(x);
		int fy=find(y);
		if(z==1)
		{
			f[fx]=fy;
		}
		else
		{
			if(fx==fy)printf("Y\n");
			else printf("N\n");
		}
	}
	return 0;
}
