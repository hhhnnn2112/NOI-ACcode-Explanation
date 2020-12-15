#include<bits/stdc++.h>
using namespace std;
long long n,ans;
priority_queue<int> q;
int main()
{
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
	{
		int x;
		scanf("%d",&x);
		q.push(x);
		if(x<q.top())
		{
			ans+=q.top()-x;
			q.pop();
			q.push(x);
		}
	}
	printf("%lld",ans);
	return 0;
}
