#include<cstdio>
#include<algorithm>

using namespace std;

const int N=1005,M=100005;

int n,m,cnt,ans;
int x,y,t;
int FatherOf[N],ancx,ancy;

struct node
{
    int x,y,t;
}e[M];

bool cmp(node a,node b)
{
    return a.t<b.t;
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
        scanf("%d%d%d",&x,&y,&t);
        e[i].x=x;
        e[i].y=y;
        e[i].t=t;
    }
    sort(e+1,e+m+1,cmp);
    for(int i=1;i<=n;++i)
        FatherOf[i]=i;
    for(int i=1;i<=m;++i)
    {
        ancx=GetA(e[i].x);
        ancy=GetA(e[i].y);
        if(ancx!=ancy)
        {
            FatherOf[ancy]=ancx;
            ++cnt;
            if(cnt==n-1)
                ans=e[i].t;
        }
    }
    if(cnt==n-1)
        printf("%d\n",ans);
    else
        printf("-1\n");
    return 0;
}