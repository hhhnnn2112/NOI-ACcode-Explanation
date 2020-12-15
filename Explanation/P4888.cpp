#include<bits/stdc++.h>
using namespace std;
char mps[2001][2001];
int l,q;
int main()
{
	scanf("%d%d",&l,&q);
	for(int i=1;i<=l;i++)
	{
		scanf(" %s",mps[i]+1);
	}
	for(int i=1;i<=q;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		int t=0,ans=0;
		while((y-t>=1&&y+t<=l)&&(mps[x][y-t]==mps[x][y+t]))
		{
			t++;
		}
		ans=max(ans,2*t-1);
		t=0;
		while((x-t>=1&&x+t<=l)&&(mps[x-t][y]==mps[x+t][y]))
		{
			t++;
		}
		ans=max(ans,t*2-1);
		printf("%d\n",ans);
	}
	return 0;
}
