#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
int n,k;
void mul(int &a[100][100],int &b[100][100])
{
	int w[100][100]={};
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			for(int k=0;k<n;k++)
			{
				w[i][j]=(w[i][j]+(long long)(a[i][k]*b[k][j])%mod)%mod;
			}
		}
	}
	memcpy(a,w,sizeof w);
}
int ans[100][100],b[100][100];
signed main()
{
	scanf("%lld%lld",&n,&k);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			scanf("%lld",&b[i][j]);
			ans[i][j]=b[i][j];
		}
	}
	for(k-=1;k;k>>=1)
	{
		if(k&1)
		{
			mul(ans,b);
		}
		mul(b,b);
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cout<<ans[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
