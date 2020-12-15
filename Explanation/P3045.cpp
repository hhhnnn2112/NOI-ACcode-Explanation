#include<bits/stdc++.h>
using namespace std;
long long n,k,m;
struct mm
{
	long long p,c;
}a[50050];
bool cmp(mm x,mm y)
{
	return x.c<y.c;
}
long long ans;
int v[50050];
priority_queue<long long,vector<long long>,greater<long long> > q1;
priority_queue<pair<long long,long long >,vector<pair<long long,long long > >, greater<pair<long long,long long> > >q2;
priority_queue<pair<long long,long long >,vector<pair<long long,long long > >, greater<pair<long long,long long> > >q3;
int main()
{
	scanf("%lld%lld%lld",&n,&k,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&a[i].p,&a[i].c);
	}
	sort(a+1,a+n+1,cmp);
	long long now=0;
	for(int i=1;i<=k;i++)
	{
		if(now+a[i].c>m)
		{
			printf("%d",i-1);
			return 0;
		}
		now+=a[i].c;
		q1.push(a[i].p-a[i].c);
		v[i]=1;
	}
	if(k==n)
	{
		printf("%d",n);
		return 0;
	}
	for(int i=k+1;i<=n;i++)
	{
		q2.push(make_pair(a[i].c,i));
		q3.push(make_pair(a[i].p,i));
	}
	ans=k;
	for(int i=k+1;i<=n;i++)
	{
		while(v[q2.top().second])q2.pop();
		while(v[q3.top().second])q3.pop();
		long long p1=q2.top().second;
		long long p2=q3.top().second;
		int ta=q2.top().first+q1.top();
		int tb=q3.top().first;
		if(ta<tb)
		{
			now+=ta;
			ans++;
			q1.pop();
			q2.pop();
			q1.push(a[p1].p-a[p2].c);
			v[p1]=1;
		}
		else
		{
			now+=tb;
			ans++;
			q3.pop();
			v[p2]=1;
		}
		if(now>m)
		{
			printf("%d",ans-1);
			return 0;
		}
	}
	printf("%d",ans);
	return 0;
}
