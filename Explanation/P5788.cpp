#include<bits/stdc++.h>
using namespace std;
stack<int> s;
int n;
int a[3000006],f[3000005];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(int i=n;i>=1;i--)
	{
		while(!s.empty()&&a[s.top()]<=a[i])
		{
			s.pop();
		}
		f[i]=s.empty()?0:s.top();
		s.push(i);
	}
	for(int i=1;i<=n;i++)
	{
		printf("%d ",f[i]);
	}
	return 0;
}
