#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

const int N=50;

int n,m,start,endd;
int low[N],p[N];
int g[N][N];
bool flag[N];

void dij(int start)
{
    memset(low,127,sizeof(low));
    low[start]=0;
    int k=start,mint=1<<30,p;
    for(int i=1;i<n;++i)
    {
        flag[k]=1;
        for(int j=1;j<=n;++j)
        {
            if(flag[j])
                continue;
            if(g[k][j]+low[k]<low[j])
                low[j]=g[k][j]+low[k];
            if(low[j]<mint)
            {
                mint=low[j];
                p=j;
            }
        }
        k=p;
        mint=1<<30;
    }
}

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j)
            g[i][j]=1<<30;
    for(int i=1;i<=m;++i)
    {
        int x,y,val;
        scanf("%d%d%d",&x,&y,&val);
        g[x][y]=g[y][x]=min(g[x][y],val);
    }
    scanf("%d%d",&start,&endd);
    dij(start);
    printf("%d\n",low[endd]);
    return 0;
}