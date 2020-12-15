#include<bits/stdc++.h>
using namespace std;
int inv[3000050];
int n,p;
int main()
{
	scanf("%d%d",&n,&p);
	inv[1]=1;
	printf("%d\n",inv[1]);
	for(int i=2;i<=n;i++)
	{
		inv[i]=(long long)inv[p%i]*(p-p/i)%p;
		printf("%d\n",inv[i]);
	}
	return 0;
}
