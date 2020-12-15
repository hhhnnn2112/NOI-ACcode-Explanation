#include<bits/stdc++.h>
using namespace std;
long long n,k,a[1000800],b[1000800];
int main()
{
	scanf("%lld%lld",&n,&k);
	for(int i=0;i<k;i++)
	{
		scanf("%lld%lld",&a[i],&b[i]);
	}
	sort(a,a+k);
	sort(b,b+k);
	long long xc=unique(a,a+k)-a;
	long long yc=unique(b,b+k)-b;
	printf("%lld",n*n-(n-xc)*(n-yc));
	return 0;
}
