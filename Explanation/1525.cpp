#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

const int N=20005,M=100005;

struct node
{
    int x,y,val;
}g[M];

int n,m;
int a[M];
int FatherOf[N];

bool cmp(node a,node b)
{
    return a.val>b.val;
}

int GetA(int x)
{
    if(x==FatherOf[x])
        return x;
    else
        return FatherOf[x]=GetA(FatherOf[x]);
}

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;++i)
    {
        int x,y,val;
        scanf("%d%d%d",&g[i].x,&g[i].y,&g[i].val);
    }
    for(int i=1;i<=n;++i)
        FatherOf[i]=i;
    sort(g+1,g+m+1,cmp);
    /*for(int i=1;i<=m;++i)
        printf("%d %d %d\n",g[i].x,g[i].y,g[i].val);*/
    for(int i=1;i<=m;++i)
    {
        int anc1=GetA(g[i].x);
        int anc2=GetA(g[i].y);

        int anc3=GetA(a[g[i].x]);
        int anc4=GetA(a[g[i].y]);

        if(anc1==anc2)//输出结果
        {
            printf("%d\n",g[i].val);
            return 0;
        }

        if(a[g[i].x]!=0 && a[g[i].y]!=0)//都不等于0
        {
            FatherOf[anc2]=anc3;
            FatherOf[anc1]=anc4;
        }

        if(a[g[i].x]==0 && a[g[i].y]==0)//都等于0
        {
            a[g[i].x]=g[i].y;
            a[g[i].y]=g[i].x;
        }

        if(a[g[i].x]==0 && a[g[i].y]!=0)//一个等于0
        {
            FatherOf[anc1]=anc4;
            a[g[i].x]=g[i].y;
        }

        if(a[g[i].x]!=0 && a[g[i].y]==0)//一个等于0
        {
            FatherOf[anc2]=anc3;
            a[g[i].y]=g[i].x;
        }
    }
    printf("0\n");
    return 0;
}