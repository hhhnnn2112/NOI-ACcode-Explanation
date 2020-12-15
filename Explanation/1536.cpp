#include<cstdio>

using namespace std;

const int N=1005,M=1000005;

int n,m,tot;
int a,b;
int FatherOf[N],ancX,ancY;

struct node
{
    int x,y;
}e[M];

int GetA(int x)
{
    if(x==FatherOf[x])
        return x;
    else
        return FatherOf[x]=GetA(FatherOf[x]);
}

int main()
{
    while(1)
    {
        scanf("%d",&n);
        if(n==0)
            break;
        scanf("%d",&m);
        for(int i=1;i<=n;++i)
            FatherOf[i]=i;
        for(int i=1;i<=m;++i)
        {
            scanf("%d%d",&a,&b);
            e[i].x=a;
            e[i].y=b;
        }
        tot=0;
        for(int i=1;i<=m;++i)
        {
            ancX=GetA(e[i].x),ancY=GetA(e[i].y);
            if(ancX!=ancY)
            {
                FatherOf[ancY]=ancX;
                ++tot;
            }
        }
        printf("%d\n",n-tot-1);
    }
    return 0;
}