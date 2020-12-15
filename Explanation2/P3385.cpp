#include<bits/stdc++.h>
using namespace std;
const int N=1000020;
int head[N],ver[N],nxt[N],edge[N],cnt,d[N];
int n,m;
queue<int > q;
bool v[N];
void add(int x,int y,int z)
{
	cnt++;
	ver[cnt]=y;
	nxt[cnt]=head[x];
	head[x]=cnt;
	edge[cnt]=z;
}
int ans[N];
int spfa(int a)
{
	memset(ans,0,sizeof ans);
	memset(v,0,sizeof v);
	memset(d,0x3f,sizeof d);
	v[a]=1;
	d[a]=0;
	q.push(a);
	while(q.size())
	{
		int x=q.front();
		q.pop();
		if(ans[x]>=n)
		{
			return 0;
		}
		v[x]=0;
		for(int i=head[x];i;i=nxt[i])
		{
			int y=ver[i],z=edge[i];
			if(d[y]>d[x]+z)
			{
				d[y]=d[x]+z;
				if(!v[y])
				{
					q.push(y);
					ans[y]++;
					v[y]=1;
				}
			}
		}
	}
	return 1;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		cnt=0;
		memset(head,0,sizeof head);
		cin>>n>>m;
		for(int i=1;i<=m;i++)
		{
			int x,y,z;
			cin>>x>>y>>z;
			if(z<0)
			{
				add(x,y,z);
			}
			else
			{
				add(x,y,z);
				add(y,x,z);
			}
		}
		if(spfa(1))
		{
			cout<<"NO"<<endl;
		}
		else
		{
			cout<<"YES"<<endl;
		}
	}
	return 0;
}
