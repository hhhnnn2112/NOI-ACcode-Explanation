#include<bits/stdc++.h>
using namespace std;
int n,m;
char c;
int w[100],b[100],r[100];
int ans=1e9;
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		w[i]+=w[i-1];
		b[i]+=b[i-1];
		r[i]+=r[i-1];
		for(int j=1;j<=m;j++)
		{
			scanf(" %c",&c);
			if(c=='W')
			{
				r[i]++;
				b[i]++;
			}
			if(c=='R')
			{
				b[i]++;
				w[i]++;
			}
			if(c=='B')
			{
				w[i]++;
				r[i]++;
			}
		}
	}
	for(int i=1;i<n-1;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			ans=min(ans,w[i]+b[j]-b[i]+r[n]-r[j]);
		}
	}
	printf("%d",ans);
	return 0;
}
