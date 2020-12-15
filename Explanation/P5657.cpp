#include<bits/stdc++.h>
using namespace std;
unsigned long long a,b;
int main()
{
	cin>>a>>b;
	b^=b/2;
	for(int i=a-1;i>=0;i--)
	{
		cout<<(b>>i&1);
	}
	return 0;
}
