#include<cstdio>
#include<cstring>

using namespace std;

const int N=105;

int n;
int g[N][N];
int k=1,low[N],vis[N],mint;
int ans;

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j)
            scanf("%d",&g[i][j]);
    memset(low,127,sizeof(low));
    for(int i=1;i<n;++i)
    {
        int pos=k;
        vis[pos]=1;
        mint=1<<30;
        for(int j=1;j<=n;++j)
            if(!vis[j])
            {
                if(low[j]>g[pos][j])
                    low[j]=g[pos][j];
                if(mint>low[j])
                {
                    mint=low[j];
                    k=j;
                }
            }
        ans+=mint;
    }
    printf("%d\n",ans);
    return 0;
}