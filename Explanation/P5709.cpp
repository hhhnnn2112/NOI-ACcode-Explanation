#include<bits/stdc++.h>
using namespace std;
int m,t,s,a;
int main()
{
	cin>>m>>t>>s;
	if(t==0)
	{
		cout<<0;
		return 0;
	}
	a=m-ceil((double)s/t);
	cout<<max(a,0);
	return 0;
}
