#include<cstdio>

using namespace std;

const int N=25;

bool way[N][N];
int n,maxx,cnt;
int a[N],used[N],go[N],ans[N];

bool dig(int k)
{
    for(int i=1;i<=n;++i)
        if(way[k][i]&&!used[i])
            return false;
    return true;
}

void dfs(int nowpos,int step,int tot)
{
    if(dig(nowpos))
    {
        if(maxx<tot)
        {
            maxx=tot;
            cnt=step;
            for(int i=1;i<=maxx;++i)
                ans[i]=go[i];
        }
        return ;
    }
    for(int i=1;i<=n;++i)
        if(way[nowpos][i]&&!used[i])
        {
            used[i]=1;
            go[step+1]=i;
            dfs(i,step+1,tot+a[i]);
            used[i]=0;
        }
}

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;++i)
        scanf("%d",&a[i]);
    for(int i=1;i<n;++i)
        for(int j=i+1;j<=n;++j)
            scanf("%d",&way[i][j]);
    for(int i=1;i<=n;++i)
    {
        used[i]=1;
        go[1]=i;
        dfs(i,1,a[i]);
        used[i]=0;
    }
    for(int i=1;i<=cnt;++i)
        printf("%d ",ans[i]);
    printf("\n%d\n",maxx);
    return 0;
}