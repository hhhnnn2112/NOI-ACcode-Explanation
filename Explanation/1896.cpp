#pragma GCC optimize(3)
#include<cstdio>
#include<algorithm>
#include<cstring>
typedef long long ll;

using namespace std;

const int N=2005;

ll n,k,cnt;
ll sta[N],sit[N],dp[15][N][105];

void dfs(int x,int num,int cur) {
    if(cur>=n) {
        ++cnt;
        sit[cnt]=x;
        sta[cnt]=num;
        return ;
    }
    dfs(x,num,cur+1);
    dfs(x+(1<<cur),num+1,cur+2);
}
int main() {
    scanf("%lld%lld",&n,&k);
    dfs(0,0,0);
    for(int i=1;i<=cnt;++i) dp[1][i][sta[i]]=1;
    for(int i=2;i<=n;++i)
        for(int j=1;j<=cnt;++j)
            for(int l=1;l<=cnt;++l) {
                if(sit[j]&sit[l]) continue;
                if((sit[j]<<1)&sit[l]) continue;
                if(sit[j]&(sit[l]<<1)) continue;
                for(int p=sta[j];p<=k;++p) dp[i][j][p]+=dp[i-1][l][p-sta[j]];
            }
    ll ans=0;
    for (int i=1;i<=cnt;++i) ans+=dp[n][i][k];
    printf("%lld\n",ans);
    return 0;
}