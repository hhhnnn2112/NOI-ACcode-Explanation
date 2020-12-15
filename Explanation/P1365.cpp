#include<bits/stdc++.h>
using namespace std;
int n;
double p[310000];
double x1[310000],x2[310000];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lf" ,&p[i]);
	}
	for(int i=1;i<=n;i++)
	{
		x1[i]=(x1[i-1]+1)*p[i];
		x2[i]=x2[i-1]+(2*x1[i-1]+1)*p[i];
	}
	printf("%.4lf",x2[n]);
	return 0;
}
