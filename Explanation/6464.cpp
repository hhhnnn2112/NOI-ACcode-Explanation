#include<cstdio>
#include<algorithm>
#include<cmath>

using namespace std;

const int N=105;

int n,m;
int g[N][N],t[N][N];
int ans=1<<30;

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j)
            g[i][j]=1<<29;
    for(int i=1;i<=m;++i)
    {
        int x,y,w;
        scanf("%d%d%d",&x,&y,&w);
        if(w<g[x][y])
            g[x][y]=g[y][x]=w;
    }
    for(int k=1;k<=n;++k)
        for(int i=1;i<=n;++i)
            for(int j=1;j<=n;++j)
            {
                if(g[i][j]>g[i][k]+g[k][j])
                g[i][j]=g[i][k]+g[k][j];
                t[i][j]=g[i][j];
            }    
    for(int i=1;i<=n;++i)
        for(int j=1;j<i;++j)
        {
            g[i][j]=g[j][i]=0;
            for(int x=1;x<=n;++x)
                for(int y=1;y<=n;++y)
                    if(g[x][y]>g[x][i]+g[i][y])
                        g[x][y]=g[x][i]+g[i][y];
            for(int x=1;x<=n;++x)
                for(int y=1;y<=n;++y)
                    if(g[x][y]>g[x][j]+g[j][y])
                    g[x][y]=g[x][j]+g[j][y];
            int cnt=0;
            for(int x=1;x<=n;++x)
                for(int y=1;y<x;++y)
                    cnt+=g[x][y];
            if(ans>cnt)
            ans=cnt;
            for(int x=1;x<=n;++x)
                for(int y=1;y<=n;++y)
                    g[x][y]=t[x][y];
        }
    printf("%d\n",ans);
    return 0;
}