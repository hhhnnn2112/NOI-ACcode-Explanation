#include<cstdio>
#include<cmath>
#include<algorithm>

using namespace std;

const int N=105,M=205;

int n,energy[N],dp[M][M],ans;

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;++i)
    {
        scanf("%d",&energy[i]);
        energy[i+n]=energy[i];
    }
    for(int i=2;i<2*n;++i)
        for(int j=i-1;j>=1;--j)
            if(i-j<n)
            {
                for(int k=j;k<i;++k)
                    dp[j][i]=max(dp[j][i],dp[j][k]+dp[k+1][i]+energy[j]*energy[k+1]*energy[i+1]); 
                ans=max(ans,dp[j][i]);
            }
    printf("%d\n",ans);
    return 0;
}