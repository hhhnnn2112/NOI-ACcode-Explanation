#include<bits/stdc++.h>
using namespace std;
int n;
int ans;
int a[10005],b[10005];
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>b[i];
	}
	sort(a+1,a+1+n);
	reverse(a+1,a+1+n);
	sort(b+1,b+1+n);
	reverse(b+1,b+1+n);
	for(int i=1,j=1,ii=n,jj=n;i<=ii;)
	{
		if(a[i]>b[j])
		{
			ans+=200;
			i++;
			j++;
		}
		else if(a[i]<b[j])
		{
			ans-=200;
			j++;
			ii--;
		}
		else
		{
			if(a[ii]>b[jj])
			{
				ans+=200;
				ii--;
				jj--;
			}
			else
			{
				if(a[ii]<b[j])
				{
					ans-=200;
				}
				ii--;
				j++;
			}
		}
	}
	cout<<ans;
	return 0;
}
