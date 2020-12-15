#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[100050];
bool judge(int t)
{
	int z=0;
	int tot=0;
	for(int i=1;i<=n;i++)
	{
		if(tot+a[i]>t)
		{
			tot=a[i];
			z++;
		}
		else
		{
			tot+=a[i];
		}
	}
	return z>=m;
}
int l,r;
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		l=max(a[i],l);
		r+=a[i];
	}
	while(l<=r)
	{
		int mid=(l+r)/2;
		if(judge(mid))
		{
			l=mid+1;
		}
		else
		{
			r=mid-1;
		}
	}
	printf("%d",l);
	return 0;
}
