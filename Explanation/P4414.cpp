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
	scanf("%s",s);
	printf("%d %d %d",a[s[0]-'A'+1],a[s[1]-'A'+1],a[s[2]-'A'+1]);
	return 0;
}
