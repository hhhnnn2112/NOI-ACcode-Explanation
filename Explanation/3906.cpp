#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>

using namespace std;

const int N=45;

int n,m,k;
int a[N],g[N][N];

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j)
            g[i][j]=1<<29;
    for(register int i=1;i<=m;++i)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        g[x][y]=g[y][x]=1;
    }
    for(int k=1;k<=n;++k)
        for(int i=1;i<=n;++i)
            for(int j=1;j<=n;++j)
                if(g[i][j]>g[i][k]+g[k][j])
                    g[i][j]=g[i][k]+g[k][j];
    scanf("%d",&k);
    int cnt;
    while(k--)
    {
        cnt=1;
        int x,y;
        scanf("%d%d",&x,&y);
        a[cnt]=x;
        for(int i=1;i<=n;++i)
            if(g[x][i]+g[i][y]==g[x][y])
            {
                ++cnt;
                a[cnt]=i;
            }
        ++cnt;
        a[cnt]=y;
        sort(a+1,a+cnt+1);
        for(int i=1;i<=cnt;++i)
            printf("%d ",a[i]);
        printf("\n");
    }
    return 0;
}