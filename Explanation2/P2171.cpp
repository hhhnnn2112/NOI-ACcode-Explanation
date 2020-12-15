#include<bits/stdc++.h>
using namespace std;
int f[30050000],ls[30005000],rs[30000050];
int n;
int deep;
int d[3005000];
void add(int r,int x)
{
	if(ls[r]==0&&f[x]<=f[r])
	{
		ls[r]=x;
		d[x]=d[r]+1;
		deep=max(deep,d[x]);
		return;
	}
	if(rs[r]==0&&f[x]>f[r])
	{
		rs[r]=x;
		d[x]=d[r]+1;
		deep=max(deep,d[x]);
		return;
	}
	if(f[x]<=f[r]&&ls[r]!=0)
	{
		add(ls[r],x);
		return;
	}
	if(f[x]>f[r]&&rs[r]!=0)
	{
		add(rs[r],x);
		return;
	}
}
void put(int r)
{
	if(ls[r])
	{
		put(ls[r]);
	}
	if(rs[r])
	{
		put(rs[r]);
	}
	cout<<f[r]<<endl;
}
int main()
{
	cin>>n;
	int root;
	for(int i=1;i<=n;i++)
	{
		int x;
		cin>>x;
		f[i]=x;
		if(i==1)
		{
			root=i;
		}
		else
		{
			add(root,i);
		}
	}
	cout<<"deep="<<deep+1<<endl;
	put(root);
	return 0;
}
