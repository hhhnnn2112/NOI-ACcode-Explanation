#include<bits/stdc++.h>
using namespace std;
const int N=2000005,M=1000000;
string s;
int maxx,len,dp=M,pos[N];//g=-1,r=1
int main()
{
	cin>>s;
	len=s.length();
	for(int i=1;i<=len;++i)
	{
		if(s[i-1]=='R')
			++dp;
		else
			--dp;
		if(!pos[dp])
			pos[dp]=i;
		else
			maxx=max(maxx,i-pos[dp]);
		if(dp==1000000)
			maxx=i;
	}
	cout<<maxx<<endl;
	return 0;
}
