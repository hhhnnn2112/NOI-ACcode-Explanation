#include<bits/stdc++.h>
using namespace std;
struct number
{
	int num,ind;
	bool sign;
	bool operator<(const number& ano)const
	{
		return num<ano.num;
	}
}p[2005];
int a[1005],b[1005],s[1005];
bool vi[1005];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		p[i].num=a[i];
		p[i].ind=i;
		p[i].sign=true;
	}
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&b[i]);
		p[i+n].num=b[i];
		p[i+n].ind=i;
		p[i+n].sign=false;
	}
	sort(p+1,p+2*n+1);
	int l=1,r=n;
	for(int i=1;i<=2*n;i++)
	{
		if(vi[p[i].ind])
			continue;
		vi[p[i].ind]=1;
		if(p[i].sign)
			s[l++]=p[i].ind;
		else
			s[r--]=p[i].ind;
		if(l>r)
			break;
	}
	int ta=0,tb=0;
	for(int i=1;i<=n;i++)
	{
		ta+=a[s[i]];
		tb=max(tb,ta);
		tb+=b[s[i]];
	}
	printf("%d\n",tb);
	for(int i=1;i<=n;i++)
		printf("%d ",s[i]);
	return 0;
}
