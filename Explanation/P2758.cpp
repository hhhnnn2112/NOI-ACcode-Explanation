#include<bits/stdc++.h>
using namespace std;
string a,b;
int f[3050][3050];
int main()
{
	cin>>a>>b;
	string c=" ";
	int sa=a.size();
	int sb=b.size();
	a=c+a;
	b=c+b;
	for(int i=1;i<=2050;i++)
	{
		f[i][0]=f[0][i]=i;
	}
	for(int i=1;i<=sa;i++)
	{
		for(int j=1;j<=sb;j++)
		{
			if(a[i]==b[j])
			{
				f[i][j]=min(f[i-1][j]+1,min(f[i][j-1]+1,f[i-1][j-1]));
			}
			else
			{
				f[i][j]=min(f[i-1][j],min(f[i][j-1],f[i-1][j-1]))+1;
			}
		}
	}
	cout<<f[sa][sb];
	return 0;
}
