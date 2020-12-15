#include<bits/stdc++.h>
using namespace std;
const int N=1005;
int n,m,c,area=-1<<30,posx,posy,a[N][N],sum[N][N];
int main()
{
	scanf("%d%d%d",&n,&m,&c);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
		{
			scanf("%d",&a[i][j]);
			sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+a[i][j];
		}
	for(int i=c;i<=n;++i)
     	for(int j=c;j<=m;++j)
          	if(sum[i][j]-sum[i-c][j]-sum[i][j-c]+sum[i-c][j-c]>area)
           	{
               	area=sum[i][j]-sum[i-c][j]-sum[i][j-c]+sum[i-c][j-c];
               	posx=i-c+1;
				posy=j-c+1;
           	}
	printf("%d %d\n",posx,posy);
	return 0;
}
