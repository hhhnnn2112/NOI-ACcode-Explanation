#include<bits/stdc++.h>
using namespace std;
#define ls (x<<1)
#define rs ((x<<1)|1)
#define mid ((l+r)>>1)
#define int long long
const int N=1e6+20;
int n,m,t[N<<2],a[N<<2];
int ad[N<<2];
void build(int x,int l,int r)
{
	if(l==r)
	{
		t[x]=a[l];
		return;
	}
	build(ls,l,mid);
	build(rs,mid+1,r);
	t[x]=min(t[ls],t[rs]);
}
void add(int x,int l,int r,int v)
{
	t[x]+=v;
	ad[x]+=v;
}
void push(int x,int l,int r)
{
	add(ls,l,mid,ad[x]);
	add(rs,mid+1,r,ad[x]);
	ad[x]=0;
}
int query(int x,int l,int r,int L,int R)
{
	int res=2e10;
	if(L>r||l>R)
	{
		return 2e10;
	}
	if(l>=L&&r<=R)
	{
		return t[x];
	}
	push(x,l,r);
	return min(query(rs,mid+1,r,L,R),query(ls,l,mid,L,R));
}
void change(int x,int l,int r,int L,int R,int v)
{
	if(L>r||l>R)
	{
		return;
	}
	if(l>=L&&r<=R)
	{
		add(x,l,r,v);
		return;
	}
	push(x,l,r);
	change(ls,l,mid,L,R,v);
	change(rs,mid+1,r,L,R,v);
	t[x]=min(t[ls],t[rs]);
}
signed main()
{
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	build(1,1,n);
	for(int i=1;i<=m;i++)
	{
		int x,y,z;
		scanf("%lld%lld%lld",&x,&y,&z);
		if(query(1,1,n,y,z)<x)
		{
			printf("-1\n");
			printf("%lld",i);
			return 0;
		}
		change(1,1,n,y,z,-x);
	}
	printf("0");
	return 0;
}
