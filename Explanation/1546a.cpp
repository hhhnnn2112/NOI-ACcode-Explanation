#include<cstdio>
#include<algorithm>

using namespace std;

const int N=105,M=10005;

struct edge
{
    int x,y,val;
}e[M];

int n,ans,cnt;
int g[N][N];
int FatherOf[N];

int GetA(int x)
{
    if(x==FatherOf[x])
        return x;
    else
        return FatherOf[x]=GetA(FatherOf[x]);
}

bool cmp(edge x,edge y)
{
    return x.val<y.val;
}

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j)
        {
            int num;
            scanf("%d",&num);
            if(j>i)
            {
                ++cnt;
                e[cnt].x=i;
                e[cnt].y=j;
                e[cnt].val=num;
            }
        }
    sort(e+1,e+cnt+1,cmp);
    for(int i=1;i<=n;++i)
        FatherOf[i]=i;
    int Number=0;
    for(int i=1;i<=cnt;++i)
    {
        int ancx=GetA(e[i].x),ancy=GetA(e[i].y);
        if(ancx!=ancy)
        {
            FatherOf[ancy]=ancx;
            ans+=e[i].val;
            ++Number;
            if(Number==n-1)
            {
                printf("%d\n",ans);
                return 0;
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}