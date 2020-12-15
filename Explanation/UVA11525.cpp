#include<bits/stdc++.h>
using namespace std;
int s[50065];
int T,k;
int sum[200500];
int L[200500],R[200500];
#define ls (x<<1)
#define rs ((x<<1)|1)
#define mid ((l+r)>>1)
void build(int x,int l,int r)
{
	L[x]=l;
	R[x]=r;
	if(l==r)
	{
		sum[x]=1;
		return ;
	}
	build(ls,l,mid);
	build(rs,mid+1,r);
	sum[x]=sum[ls]+sum[rs];
}
int query(int x,int v)
{
	if(L[x]==R[x])
	{
		sum[x]=0;
		return L[x];
	}
	int res=0;
	if(v<=sum[ls])
	{
		res=query(ls,v);
	}
	else
	{
		res=query(rs,v-sum[ls]);
	}
	sum[x]=sum[ls]+sum[rs];
	return res;
}
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&k);
		build(1,1,k);
		for(int i=1;i<=k;i++)
		{
			int x;
			scanf("%d",&x);
			printf("%d",query(1,x+1));
			if(i!=k)printf(" ");
		}
		puts("");
	}
	return 0;
} 
