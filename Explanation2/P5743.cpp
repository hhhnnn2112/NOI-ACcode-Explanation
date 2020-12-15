#include<bits/stdc++.h>
using namespace std;
int n;
int main()
{
	cin>>n;
	int x=1;
	while(--n)
	{
		x+=1;
		x*=2;
	}
	cout<<x;
	return 0;
}
