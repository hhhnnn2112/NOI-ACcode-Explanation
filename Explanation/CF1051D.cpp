/**
 * dp[i][j][k]: 前i列，有j个联通块，第i列状态为k的方案数
 */
#include<cstdio>
typedef long long ll;

using namespace std;

const ll N=1005,MOD=998244353;

ll n,k,dp[N][N*2][4];

int main() {
    scanf("%lld%lld",&n,&k);
    dp[1][1][0]=dp[1][1][3]=dp[1][2][1]=dp[1][2][2]=1;
    for(register int i=2;i<=n;++i)
        for(register int j=0;j<=k;++j) {
            dp[i][j][0]+=((dp[i-1][j][0]+dp[i-1][j][1])%MOD+(dp[i-1][j][2]+dp[i-1][j-1][3])%MOD)%MOD;
            dp[i][j][0]%=MOD;
            dp[i][j][1]+=((dp[i-1][j-1][0]+dp[i-1][j][1])%MOD+(dp[i-1][j-2][2]+dp[i-1][j-1][3])%MOD)%MOD;
            dp[i][j][1]%=MOD;
            dp[i][j][2]+=((dp[i-1][j-1][0]+dp[i-1][j-2][1])%MOD+(dp[i-1][j][2]+dp[i-1][j-1][3])%MOD)%MOD;
            dp[i][j][2]%=MOD;
            dp[i][j][3]+=((dp[i-1][j-1][0]+dp[i-1][j][1])%MOD+(dp[i-1][j][2]+dp[i-1][j][3])%MOD)%MOD;
            dp[i][j][3]%=MOD;
        }
    printf("%lld\n",(dp[n][k][0]+dp[n][k][1]+dp[n][k][2]+dp[n][k][3])%MOD);
    return 0;
}