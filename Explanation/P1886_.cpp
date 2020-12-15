#include<bits/stdc++.h>
using namespace std;
int a[1000005];
int n,k;
int qma[1000005],qmi[1000005];
void ma()
{
	int head=0,tail=0;
	for(int i=1;i<=n;i++)
	{
		while(head<=tail&&a[qma[tail]]<a[i])
		{
			tail--;
		}
		while(head<=tail&&qma[head]+k<=i)
		{
			head++;
		}
		qma[++tail]=i;
		if(i>=k)
		{
			printf("%d ",a[qma[head]]);
		}
	}
	
}
void mi()
{
	int head=0,tail=0;
	for(int i=1;i<=n;i++)
	{
		while(head<=tail&&a[qmi[tail]]>a[i])
		{
			tail--;
		}
		while(head<=tail&&qmi[head]+k<=i)
		{
			head++;
		}
		qmi[++tail]=i;
		if(i>=k)
		{
			printf("%d ",a[qmi[head]]);
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
	mi();
	puts("");
	ma();
	return 0;
}
