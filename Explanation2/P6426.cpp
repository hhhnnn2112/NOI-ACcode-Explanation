#include<bits/stdc++.h>
using namespace std;
int a,b,c;
int main()
{
	scanf("%d%d%d",&a,&b,&c);
	printf("%d",max(b-a-1,c-b-1));
	return 0;
}
