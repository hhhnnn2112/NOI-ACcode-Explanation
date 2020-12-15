#include<bits/stdc++.h>
using namespace std;
int v[100000009];
int p[6000005],pc;
int n,q,k;
int main()
{
	scanf("%d%d",&n,&q);
	for(int i=2;i<=n;i++)
	{
		if(!v[i])
		{
			p[pc++]=i;
		}
		for(int j=0;j<pc&&i*p[j]<=n;j++)
		{
			v[i*p[j]]=p[j];
			if(v[i]==p[j])
			{
				break;
			}
		}
	}
	for(int i=0;i<q;i++)
	{
		scanf("%d",&k);
		printf("%d\n",p[k-1]);
	}
	return 0;
}
