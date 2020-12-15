#include<bits/stdc++.h>
using namespace std;
const int N=125;
int n,a[N][N],sum[N][N],area,ans=-1<<30;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
		{
			scanf("%d",&a[i][j]);
			sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+a[i][j];
		}
	//×óÉÏ½Ç×ø±ê(xi,yi)£¬ÓÒÏÂ½Ç×ø±ê(xj,yj) 
	for(int xi=1;xi<=n;++xi)
		for(int xj=xi;xj<=n;++xj)
			for(int yi=1;yi<=n;++yi)
				for(int yj=yi;yj<=n;++yj)
				{
					area=sum[xj][yj]-sum[xi-1][yj]-sum[xj][yi-1]+sum[xi-1][yi-1];
					ans=max(ans,area);
				}
	printf("%d\n",ans);
	return 0;
}
