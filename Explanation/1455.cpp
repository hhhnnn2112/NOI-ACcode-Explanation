#include<cstdio>
#include<algorithm>

using namespace std;

const int N=10005;

int n,m,t;
int w[N],val[N],dp[N],FatherOf[N];

int GetA(int x)
{
    if(x==FatherOf[x])
        return x;
    else
        return FatherOf[x]=GetA(FatherOf[x]);
}

int main()
{
    scanf("%d%d%d",&n,&m,&t);
    for(int i=1;i<=n;++i)
    {
        scanf("%d%d",&w[i],&val[i]);
        FatherOf[i]=i;
    }
    for(int i=1;i<=m;++i)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        if(GetA(x)!=GetA(y))
            FatherOf[GetA(y)]=GetA(x);
    }
    for(int i=1;i<=n;++i)
        if(FatherOf[i]!=i)
        {
            val[GetA(i)]+=val[i];
            w[GetA(i)]+=w[i];
            val[i]=w[i]=0;
        }
    for(int i=1;i<=n;++i)
        for(int j=t;j>=w[i];--j)
            dp[j]=max(dp[j],dp[j-w[i]]+val[i]);
    printf("%d\n",dp[t]);
    return 0;
}