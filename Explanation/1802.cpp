#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
typedef long long ll;
using namespace std;
const int N=1005;
ll n,x,lose[N],win[N],use[N],dp[N];
int main()
{
    scanf("%lld%lld",&n,&x);
    for(int i=1;i<=n;++i)
        scanf("%lld%lld%lld",&lose[i],&win[i],&use[i]);
    for(int i=1;i<=n;++i)
        for(ll j=x;j>=0;--j)
            if(j>=use[i])
                dp[j]=max(dp[j]+lose[i],dp[j-use[i]]+win[i]);
            else
                dp[j]+=lose[i];
    printf("%lld\n",dp[x]*5);
    return 0;
}
/*
下述循环语句等价于for(LL j=x;j>=0;++j)的部分
主要区分了if语句的不同范围
for(LL j=x;j>=use[i];--j)
    dp[j]=max(dp[j]+lose[i],dp[j-use[i]]+win[i]);
for(LL j=use[i]-1;j>=0;--j)
    dp[j]+=lose[i];
特别地，如果开int类型，会90分。原因是：最终的经验超出了int的范围。
另外，五倍经验*5，答案也可能超出int。
*/
