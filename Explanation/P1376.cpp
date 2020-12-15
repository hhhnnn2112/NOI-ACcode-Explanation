#include<bits/stdc++.h>
using namespace std;
long long  n,s,ans;
int minn=0x3f3f3f3f;
int main()
{
	scanf("%lld%lld",&n,&s);
	for(int i=1;i<=n;i++)
	{
		long long c,y;
		scanf("%lld%lld",&c,&y);
		minn=min(minn+s,c);
		ans+=minn*y;
	}
	printf("%lld",ans);
	return 0;
}
