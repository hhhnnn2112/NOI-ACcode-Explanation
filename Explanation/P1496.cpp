#include<bits/stdc++.h>
using namespace std;
int n;
int ans;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		int x;
		scanf("%d",&x);
		ans^=x;
	}
	printf("%d",ans);
	return 0;
}
