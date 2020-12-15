#include<cstdio>

using namespace std;

const int N=10005;

int n,m;
int FatherOf[N];

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
    for(int i=1;i<=n;++i)
        FatherOf[i]=i;
    for(int i=1;i<=m;++i)
    {
        int z,x,y;
        scanf("%d%d%d",&z,&x,&y);
        if(z==1)//将y合并到x
        {
            int AncestorX,AncestorY;
            AncestorX=GetA(x);
            AncestorY=GetA(y);
            FatherOf[AncestorY]=AncestorX;
        }
        else
        {
            int AncestorX,AncestorY;
            AncestorX=GetA(x);
            AncestorY=GetA(y);
            if(AncestorX==AncestorY)
                printf("Y\n");
            else
                printf("N\n");
        }
    }
    return 0;
}