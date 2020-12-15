#include<cstdio>
#include<cstring>
#include<queue>

using namespace std;

const int N=1505;

queue <int> q;
int n,m;
int g[N][N];
int val[N];

void bfs()
{
    while(!q.empty())
    {
        int t=q.front();
        q.pop();
        for(int i=1;i<=n;++i)
            if(g[t][i] && val[i]<val[t]+g[t][i])
            {
                val[i]=val[t]+g[t][i];
                q.push(i);
            }
    }
}

int main()
{
    scanf("%d%d",&n,&m);
    memset(val,-1,sizeof(val));
    val[1]=0;
    for(int i=1;i<=m;++i)
    {
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        if(w>g[u][v])
            g[u][v]=w;
    }
    q.push(1);
    bfs();
    printf("%d\n",val[n]);
    return 0;
}