#include<bits/stdc++.h>
using namespace std;
const int N=10005;
int k,n,a[N],dplr[N],dprl[N],ans;//lr´Ó×óÍùÓÒ£¬rl´ÓÓÒÍù×ó 
int main()
{
	scanf("%d",&k);
	while(k--)
	{
		ans=0;
		scanf("%d",&n);
		for(int i=1;i<=n;++i)
		{
			scanf("%d",&a[i]);
			dplr[i]=dprl[i]=1;
		}
		for(int i=2;i<=n;++i)
			for(int j=1;j<i;++j)
				if(a[i]<a[j])
					dplr[i]=max(dplr[i],dplr[j]+1);
				else if(a[i]>a[j])
					dprl[i]=max(dprl[i],dprl[j]+1);
		for(int i=1;i<=n;++i)
			ans=max(ans,max(dplr[i],dprl[i]));
		printf("%d\n",ans);
	}
	return 0;
}
