#include<iostream>
using namespace std;
const int N=45005,M=10005;
int dp[N],w[M],c[M],n,m;
int main()
{
    cin>>m>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>c[i];
        w[i]=c[i];
    }
    for(int i=1;i<=n;i++)
        for(int j=m;j>=c[i];j--)
            dp[j]=max(dp[j],dp[j-c[i]]+w[i]);
    cout<<dp[m]<<endl;
    return 0;
}
