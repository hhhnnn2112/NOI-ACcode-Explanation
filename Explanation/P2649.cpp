#include<bits/stdc++.h>
using namespace std;
int n,m;
int v[1050];
int a,b;
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int x;
		scanf("%d",&x);
		v[x]=1;
	}
	for(int i=n*m;i>=1;i--)
	{
		if(!v[i])
		{
			b++;
		}
		if(v[i]&&!b)
		{
			a++;
		}
		if(v[i]&&b)
		{
			b--;
		}
	}
	printf("%d",a);
	return 0;
}
