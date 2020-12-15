#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int sm[N<<2];
int v[N<<2];
int n,m;
#define ls (x<<1)
#define rs (x<<1|1)
#define mid ((l+r)>>1)
void build(int x,int l,int r)
{
	if(l==r)
	{
		scanf("%1d",&sm[x]);
		return;
	}
	build(ls,l,mid);
	build(rs,mid+1,r);
	sm[x]=sm[ls]+sm[rs];
}
void change(int x,int l,int r,int L,int R)
{
	if(r<L||R<l)
	{
		return;
	}
	if(L<=l&&r<=R)
	{
		v[x]^=1;
		sm[x]=r-l+1-sm[x];
		return;
	}
	change(ls,l,mid,L,R);
	change(rs,mid+1,r,L,R);
	sm[x]=sm[ls]+sm[rs];
	if(v[x])
	{
		sm[x]=r-l+1-sm[x];
	}
}
int query(int x,int l,int r,int L,int R)
{
	int res=0;
	if(r<L||R<l)
	{
		return 0;
	}
	if(L<=l&&r<=R)
	{
		return sm[x];
	}
	res=query(ls,l,mid,L,R)+query(rs,mid+1,r,L,R);
	if(v[x])
	{
		res=min(r,R)-max(l,L)+1-res;
	}
	return res;
}
int main()
{
	scanf("%d%d",&n,&m);
	build(1,1,n);
	for(int i=1;i<=m;i++)
	{
		int op,l,r;
		scanf("%d%d%d",&op,&l,&r);
		if(op==0)
		{
			change(1,1,n,l,r);
		}
		else
		{
			printf("%d\n",query(1,1,n,l,r));
		}
	}
	return 0;
}
