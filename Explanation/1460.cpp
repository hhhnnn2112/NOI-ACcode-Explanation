#include<cstdio>

using namespace std;

const int N=30;

int v,g;
int a[N],food[N][N];//a[i]代表第i头奶牛每种维他命最小量，food[i][j]代表包含维他命量的多少
int cnt=1<<30,ans[N];
int sol[N];

bool enough(int k)
{
    for(int i=1;i<=v;++i)
    {
        int tot=0;
        for(int j=1;j<=k;++j)
            tot+=food[ans[j]][i];
        if(tot<a[i])
            return false;
    }
    return true;
}

void dfs(int nowpos,int num)//当前位置，递归第几层
{
    if(enough(num-1))
    {
        if(num-1<cnt)
        {
            cnt=num-1;
            for(int i=1;i<=cnt;++i)
                sol[i]=ans[i];
        }
        return ;
    }
    for(int i=nowpos;i<=g;++i)
    {
        ans[num]=i;
        dfs(i+1,num+1);
    }
}

int main()
{
    scanf("%d",&v);
    for(int i=1;i<=v;++i)
        scanf("%d",&a[i]);
    scanf("%d",&g);
    for(int i=1;i<=g;++i)
        for(int j=1;j<=v;++j)
            scanf("%d",&food[i][j]);

    dfs(1,1);
    printf("%d ",cnt);
    for(int i=1;i<=cnt;++i)
        printf("%d ",sol[i]);
    printf("\n");
    return 0;
}