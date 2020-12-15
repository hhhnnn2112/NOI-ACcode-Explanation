#include<bits/stdc++.h>
using namespace std;
int n;
int a[200010];
long long aa,bb;
int fa[200010];
int fb[200010];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		if(a[i]>0)
		{
			fa[i]=fa[i-1]+1;
			fb[i]=fb[i-1];
		}
		if(a[i]<0)
		{
			fa[i]=fb[i-1];
			fb[i]=fa[i-1]+1;
		}
		aa+=fa[i];
		bb+=fb[i];
	}
	printf("%lld %lld",bb,aa);
	return 0;
}
