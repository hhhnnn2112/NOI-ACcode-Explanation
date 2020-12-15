#include<bits/stdc++.h>
using namespace std;
const int N=125;
int n,a[N][N],tot,ans=-1<<30;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			scanf("%d",&a[i][j]);
	for(int xi=1;xi<=n;++xi)
		for(int xj=xi;xj<=n;++xj)
			for(int yi=1;yi<=n;++yi)
				for(int yj=yi;yj<=n;++yj)
				{
					tot=0;
					for(int i=xi;i<=xj;++i)
						for(int j=yi;j<=yj;++j)
							tot+=a[i][j];
					ans=max(ans,tot);
				}
	printf("%d\n",ans);
	return 0;
}
