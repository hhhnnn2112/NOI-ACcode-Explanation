#include<cstdio>
#include<algorithm>

using namespace std;

const int N=1005,M=10005;

struct node
{
    int x,y,val;
}e[M];

int n,m,k,tot,cnt;
int FatherOf[N],ancx,ancy;

bool cmp(node a,node b)
{
    return a.val<b.val;
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
    scanf("%d%d%d",&n,&m,&k);
    /*if(n-m>k)
    {
        printf("-1\n");
        return 0;
    }*/
    for(int i=1;i<=m;++i)
    {
        int x,y,l;
        scanf("%d%d%d",&x,&y,&l);
        e[i].x=x;
        e[i].y=y;
        e[i].val=l;
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
            FatherOf[ancx]=ancy;
            tot+=e[i].val;
            ++cnt;
            if(n-cnt==k)
            {
                printf("%d\n",tot);
                return 0;
            }
        }
    }
    printf("No Answer\n");
    return 0;
}