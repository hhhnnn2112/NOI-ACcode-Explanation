#include<bits/stdc++.h>//1507
using namespace std;
const int N=105,M=25005;
int times,n,a[N],ans;
bool f[M];
int main()
{
	cin>>times;
	for(int task=1;task<=times;++task)
	{
		memset(f,0,sizeof(f));
		f[0]=1;
		cin>>n;
		ans=n;
		for(int i=1;i<=n;++i)
			cin>>a[i];
		sort(a+1,a+n+1);
		for(int i=1;i<=n;++i)
		{
			if(!f[a[i]])
				for(int j=a[i];j<=a[n];++j)
					f[j]=max(f[j],f[j-a[i]]);
			else
				--ans;
		}
		cout<<ans<<endl; 
	}
	return 0;
}
