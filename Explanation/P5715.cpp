#include<bits/stdc++.h>
using namespace std;
int a[5];
char s[5];
int main()
{
	for(int i=1;i<=3;i++)
	{
		scanf("%d",a+i);
	}
	sort(a+1,a+1+3);
	printf("%d %d %d",a[1],a[2],a[3]);
	return 0;
}
