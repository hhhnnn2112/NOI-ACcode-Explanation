#include<bits/stdc++.h>
using namespace std;
int n,k;
int ma[1000006],mi[1000006],a[1000006];
void qmin()
{
	int head=0;
	int tail=0;
	for(int i=1;i<=n;i++)
	{
		while(head<=tail&&mi[head]+k<=i)
		{
			head++;
		}
		while(head<=tail&&a[mi[tail]]>a[i])
		{
			tail--;
		}
		mi[++tail]=i;
		if(i>=k)
		{
			printf("%d ",a[mi[head]]);
		}
	}
}
void qmax()
{
	int head=0;
	int tail=0;
	for(int i=1;i<=n;i++)
	{
		while(head<=tail&&ma[head]+k<=i)
		{
			head++;
		}
		while(head<=tail&&a[ma[tail]]<a[i])
		{
			tail--;
		}
		ma[++tail]=i;
		if(i>=k)
		{
			printf("%d ",a[ma[head]]);
		}
	}
}
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	qmin();
	puts("");
	qmax();
	return 0;
}
