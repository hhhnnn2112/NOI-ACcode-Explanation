#include<bits/stdc++.h>
using namespace std;
long long t[106000];
long long n;
long long ans[106000];
long long a[106000];
long long lowbit(long long x)
{
	return x&-x;
}
void ins(long long x,long long y)
{
	while(x<=n)
	{
		t[x]+=y;
		x+=lowbit(x);
	}
}
long long req(long long x)
{
	long long rs=0;
	while(x>0)
	{
		rs+=t[x];
		x-=lowbit(x);
	}
	return rs;
}
int main()
{
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		a[i]++;
	}
	for(int i=1;i<=n;i++)
	{
		ins(a[i],1);
		ans[a[i]]+=i-req(a[i]);	
	}
	cout<<"0\n";
	for(int i=1;i<n;i++)
	{
		ans[i]=ans[i-1]+ans[i];
		cout<<ans[i]<<endl;
	}
	return 0;
}
