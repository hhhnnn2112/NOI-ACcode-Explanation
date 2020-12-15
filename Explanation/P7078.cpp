#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5,inf=1e9;
int t,n,a[N];
pair<int,int> q1[N],q2[N];
int l1,l2,r1,r2;
pair<int,int> getmax()
{
	if(r1==l1)return q2[l2++];
	else if(r2==l2)return q1[--r1];
	else if(q2[l2]>q1[r1-1])return q2[l2++];
	else return q1[--r1]; 
}
pair<int,int> getmin()
{
	if(r1==l1)return q2[--r2];
	else if(r2==l2)return q1[l1++];
	else if(q2[r2-1]<q1[l1])return q2[--r2];
	else return q1[l1++]; 
}
pair<int,int> minn(pair<int,int> x,pair<int,int> y)
{
	return x<y?x:y;
}
void solve()
{
	l1=r1=l2=r2=0;
	for(int i=1;i<=n;i++)
	{
		q1[r1++]=make_pair(a[i],i);
	}
	int fl=0,cnt=0,alf=0;
	while(1)
	{
		++cnt;
		pair<int,int> x=getmin(),y=getmax();
		pair<int,int> z=minn(l1<r1?q1[l1]:make_pair(inf,-inf),(l2<r2?q2[r2-1]:make_pair(inf,-inf)));
		y.first-=x.first;
		if(y>z||cnt==n-1)
		{
			if(fl)
			{
				printf("%d\n",n-(fl-(alf&1)));
				return;
			}
			if(cnt==n-1)
			{
				printf("1\n");
				return;
			}
			q2[r2++]=y;
		}
		else
		{
			alf++;
			if(!fl)fl=cnt;
			q2[r2++]=y;
		}
	}
}
int k;
int main()
{
	scanf("%d%d",&t,&n);
	t-=1;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	solve();
	while(t--)
	{
		scanf("%d",&k);
		for(int i=1,x;i<=k;i++)
		{
			scanf("%d",&x);
			scanf("%d",&a[x]);
		}
		solve();
	}
	return 0;
}
