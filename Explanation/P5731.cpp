#include<bits/stdc++.h>
using namespace std;
int a[10][10];
int main()
{
	int n;
	scanf("%d",&n);
	int x=1;
	int i=1,j=1;
	a[1][1]=1;
	for(;x<n*n;)
	{
		while(a[i][j+1]==0&&j+1<=n)
		{
			j++;
			a[i][j]=++x;
		}
		while(a[i+1][j]==0&&i+1<=n)
		{
			i++;
			a[i][j]=++x;
		}
		while(a[i][j-1]==0&&j-1>=1)
		{
			j--;
			a[i][j]=++x;
		}
		while(a[i-1][j]==0&&i-1>=1)
		{
			i--;
			a[i][j]=++x;
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(a[i][j]<10)
			{
				printf(" ");
			}
			printf(" %d",a[i][j]);
		}
		puts("");
	}
	return 0;
 } 
