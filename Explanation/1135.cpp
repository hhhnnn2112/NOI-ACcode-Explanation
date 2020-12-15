#include<cstdio>
#include<cstring>

using namespace std;

const int N=205;

int n,a,b;
int ans=1<<30;
int go[N],vis[N];

void dfs(int floor,int cnt)
{
    if(floor==b && ans>cnt)
        ans=cnt;
    if(cnt>ans)
        return ;
    vis[floor]=1;
    if(floor+go[floor]<=n && !vis[floor+go[floor]])
        dfs(floor+go[floor],cnt+1);
    if(floor-go[floor]>=1 && !vis[floor-go[floor]])
        dfs(floor-go[floor],cnt+1);
    vis[floor]=0;   
}

int main()
{
    scanf("%d%d%d",&n,&a,&b);
    for(int i=1;i<=n;++i)
        scanf("%d",&go[i]);
    vis[a]=1;
    dfs(a,0);
    if(ans==(1<<30))
        printf("-1\n");
    else    
        printf("%d\n",ans);
    return 0;
}