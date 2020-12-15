#include<bits/stdc++.h> 
using namespace std;
string s;
int ans,g,r;
int main()
{
    cin>>s;
    ans=0;
    for(int i=0;i<s.length();i++)
    	for(int j=i+1;j<s.length();j++)
    	{
        	g=r=0;
        	for(int k=i;k<=j;k++)
        		if(s[k]=='G')
        			g++;
        		else
					r++;
        	if(g==r)
        		ans=max(ans,g*2);
    }
    cout<<ans<<endl;
    return 0;
}

