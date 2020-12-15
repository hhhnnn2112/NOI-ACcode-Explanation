#include<bits/stdc++.h>
using namespace std;
int ma[1000006][25];
int query(int l,int r)
{
	int k=log2(r-l+1);
	return max(ma[l][k],ma[r-(1<<k)+1][k]);
}
int n,m;
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&ma[i][0]);
	}
	for(int i=1;i<=21;i++)
	{
		for(int j=1;j+(1<<i)-1<=n;j++)
		{
			ma[j][i]=max(ma[j][i-1],ma[j+(1<<(i-1))][i-1]);
		}
	}
	for(int i=1;i<=m;i++)
	{
		int l,r;
		scanf("%d %d",&l,&r);
		printf("%d\n",query(l,r));
	}
	return 0;
}
