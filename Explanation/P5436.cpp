#include<bits/stdc++.h>
using namespace std;
int T;
long long n;
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%lld",&n);
		if(n==1)
		{
			cout<<"1"<<endl;
			continue;
		}
		printf("%lld\n",n*(n-1));
	}
	return 0;
}
