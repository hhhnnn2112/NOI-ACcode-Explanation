#include<cstdio>
#include<cstring>

using namespace std;

const int N=300005;

int m,s,t;
int dp[N];

int main()
{
    
    scanf("%d%d%d",&m,&s,&t);
    /*memset(dp,127,sizeof(dp));
    dp[0]=0;*/
    for(int i=1;i<=t;++i)
        if(m>=10)
        {
            dp[i]=dp[i-1]+60;
            m-=10;
        }
        else
        {
            dp[i]=dp[i-1];
            m+=4;
        }
    for(int i=1;i<=t;++i)
    {
        if(dp[i]<dp[i-1]+17)
            dp[i]=dp[i-1]+17;
        if(dp[i]>=s)
        {
            printf("Yes\n%d\n",i);
            return 0;
        }
    }
    printf("No\n%d\n",dp[t]);
    return 0;
}