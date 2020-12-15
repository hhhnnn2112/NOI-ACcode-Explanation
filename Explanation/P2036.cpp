#include<bits/stdc++.h>
using namespace std;
int s[20],k[20];
int n;
int ans=2147483647;
void dfs(int x,int ss,int kk)
{
	if(x>n)
	{
		if(ss==1&&kk==0)
		{
			return;
		}
		ans=min(ans,abs(ss-kk));
		return;
	}
	dfs(x+1,ss*s[x],kk+k[x]);
	dfs(x+1,ss,kk);
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&s[i],&k[i]);
	}
	dfs(1,1,0);
	printf("%d",ans);
	return 0;
}
