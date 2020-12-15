#include<cstdio>
#include<algorithm>

using namespace std;

const int N=5005,M=200005;

int n,m,bignum;
int FatherOf[N];

struct edge
{
    int x,y,val;
}e[M];

bool cmp(edge x,edge y)
{
    return x.val<y.val;
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
        scanf("%d%d%d",&e[i].x,&e[i].y,&e[i].val);
    sort(e+1,e+m+1,cmp);
    for(int i=1;i<=n;++i)
        FatherOf[i]=i;
    for(int i=1;i<=m;++i)
    {
        int ancx=GetA(e[i].x),ancy=GetA(e[i].y);
        if(ancx!=ancy)
        {
            FatherOf[ancy]=ancx;
            if(e[i].val>bignum)
                bignum=e[i].val;
        }
    }
    printf("%d %d\n",n-1,bignum);
    return 0;
}