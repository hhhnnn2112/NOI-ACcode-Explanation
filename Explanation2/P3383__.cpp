#include<bits/stdc++.h>
using namespace std;
const int N=1e8+10;
int prime[N],pri[N];
int cnt;
void init(int x)
{
	prime[1]=1;
	for(int i=2;i<=x;i++)
	{
		if(!prime[i])
		{
			pri[++cnt]=i;
		}
		for(int j=1;j<=cnt&&i*pri[j]<=x;j++)
		{
			prime[i*pri[j]]=1;
			if(i%pri[j]==0)break;
		}
	}
}
int n,q;
int main()
{
	scanf("%d%d",&n,&q);
	init(n);
	for(int i=1;i<=q;i++)
	{
		int x;
		scanf("%d",&x);
		printf("%d\n",pri[x]);
	}
	return 0;
}
