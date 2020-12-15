#include<bits/stdc++.h>
using namespace std;
int n,m;
int search(int pos,int step)
{
	if(step==m)
		if(pos==1)
			return 1;
		else
			return 0;
	if(pos!=1)
		return search(pos%n+1,step+1)+search(pos-1,step+1);
	else
		return search(pos%n+1,step+1)+search(n,step+1);
}
int main()
{
	scanf("%d%d",&n,&m);
	printf("%d\n",search(1,0));
	return 0;
}
