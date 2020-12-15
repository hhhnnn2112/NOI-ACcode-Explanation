#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long
ull base=987;
ull a[10010];
char s[10010];
int n,ans;
int prime=233317;
ull mod=156446948423;
ull hush(char s[])
{
	int len=strlen(s);
	ull ans=0;
	for(int i=0;i<len;i++)
	{
		ans=(ans*base+(ull)s[i])%mod+prime;
	}
	return ans;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf(" %s",&s);
		a[i]=hush(s);
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
	{
		if(a[i]!=a[i+1])
		{
			ans++;
		}
	}
	printf("%d",ans);
	return 0;
}
