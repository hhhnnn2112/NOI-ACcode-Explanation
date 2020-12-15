#include<bits/stdc++.h>
using namespace std;
int n,m,a[120][120],f[120][120];
void print(int x,int y)
{
	if(x==0)
	{
		return;
	}
	if(f[x][y]==f[x][y-1])
	{
		print(x,y-1);
	}
	else
	{
		print(x-1,y-1);
		printf("%d ",y);
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		f[i][0]=-1e9;
		for(int j=1;j<=m;j++)
		{
			scanf("%d",&a[i][j]);
			f[i][j]=max(f[i][j-1],f[i-1][j-1]+a[i][j]);
		}
	}
	printf("%d\n",f[n][m]);
	print(n,m);
	return 0;
}
