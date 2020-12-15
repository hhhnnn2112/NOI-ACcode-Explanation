#include<bits/stdc++.h>
using namespace std;
const int N=1005;
int n,beginlevel,maxlevel,a[N],dp[N][N];//dp[i][j]第i首歌能否到达j音量 
int main()
{
	scanf("%d%d%d",&n,&beginlevel,&maxlevel);
	dp[0][beginlevel]=1;//初始状态：第0首歌，刚开始音量beginlevel 
	for(int i=1;i<=n;++i)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;++i)
		for(int j=0;j<=maxlevel;++j)//第1~n首歌，每次循环一次音量 
		{
			if(dp[i-1][j]&&a[i]+j<=maxlevel)//若第i-1首歌能到达j音量，第i首歌改变的音量加当前音量小于最大值 
				dp[i][a[i]+j]=1; 
			if(dp[i-1][j]&&j-a[i]>=0)//若第i-1首歌能当达j音量，当前音量减第i首歌改变的音量 小于最小值 
				dp[i][j-a[i]]=1;
		}
	for(int i=maxlevel;i>=0;--i)
		if(dp[n][i])
		{
			printf("%d\n",i);
			return 0;
		}
	printf("-1\n");
	return 0;
}
