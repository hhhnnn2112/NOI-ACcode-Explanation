#include<bits/stdc++.h>
using namespace std;
int ta,tb,tc;
vector<int> ans;
vector<pair<int ,int > > che;
void ss(int a,int b,int c)
{
	vector<pair<int,int> >::iterator tt=find(che.begin(),che.end(),make_pair(a,b));
	if(tt!=che.end())
	{
		return;
	}
	che.push_back(make_pair(a,b));
	if(a==0)
	{
		vector<int>::iterator it=find(ans.begin(),ans.end(),c);
		if(it!=ans.end())
		{
			return;
		}
		else ans.push(c);
	}
	if(c+a>=ta)
	{
		ss(ta,b,c+a-ta);
	}
	else//c+a<ta
	{
		ss(c+a,b,0);
	}
	if(c+b>=tb)
	{
		ss(a,tb,c+b-tb);
	}
	else
	{
		ss(a,c+b,0);
	}
	if(b+c>=tc)
	{
		ss(a,b+c-tc,tc);
	}
	else
	{
		ss(a,0,b+c);
	}
	if(b+a>=ta)
	{
		ss(ta,b+a-ta,c);
	}
	else
	{
		ss(b+a,0,c);
	}
	if(a+c>=tc)
	{
		ss(a+c-tc,b,tc);
	}
	else
	{
		ss(0,b,a+c);
	}
	if(a+b>=tb)
	{
		ss(a+b-tb,tb,c);
	}
	else
	{
		ss(0,a+b,c);
	}
}
int a[25];
int main()
{
	scanf("%d%d%d",&ta,&tb,&tc);
	ss(0,0,tc);
	for(int i=0;i<ans.size();i++)
	{
		a[i]=ans[i];
	}
	sort(a,a+ans.size());
	for(int i=0;i<ans.size();i++)
	{
		printf("%d ",a[i]);
	}
	return 0;
}
