#include<bits/stdc++.h>
using namespace std;
int l,m;
int a[10005];
int main()
{
	
	scanf("%d%d",&l,&m);
	for(int i=1;i<=m;i++)
	{
		int ll,rr;
		scanf("%d%d",&ll,&rr);
		a[ll]++;
		a[rr+1]--;
	}
	int ans=0;
	if(a[0]==0)ans++;
	for(int i=1;i<=l;i++)
	{
		a[i]+=a[i-1];
		if(a[i]==0)ans++;
	}
	printf("%d",ans);
	return 0;
} 
/*
题面
P1047

syx的O（n）
我的标程 按luogu数据写的记得改
可以卡O（n2）卡到60分甚至更低

扩大  m  l  的范围
增加询问个数  和询问区间长度
*/
