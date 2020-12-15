#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;
const int N=2505;
int n,m,t,sum[N],dp[N];
int main()
{
    memset(dp,127,sizeof(dp));
    dp[0]=0;
    scanf("%d%d",&n,&m);
    sum[0]=m;
    for(int i=1;i<=n;++i)
    {
        scanf("%d",&t);
        sum[i]=sum[i-1]+t;
    }
    for(int i=1;i<=n;++i)
        for(int j=1;j<=i;++j)
            dp[i]=min(dp[i],dp[i-j]+sum[j]+m);
    printf("%d\n",dp[n]-m);
    return 0;
}
