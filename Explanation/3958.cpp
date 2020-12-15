#include<cstdio>
#include<algorithm>
#include<cmath>

using namespace std;

const int N=1005;

int t;
int n,h,r;
int FatherOf[N],ancx,ancy;

struct node
{
    int x,y,z,num;
}pos[N];

int GetA(int x)
{
    if(x==FatherOf[x])
        return x;
    else
        return FatherOf[x]=GetA(FatherOf[x]);
}

int area(int a)
{
    return a*a;
}

double dist(node a,node b)
{
    return sqrt(area(a.x-b.x)*1.0+area(a.y-b.y)+area(a.z-b.z));
}

int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d",&n,&h,&r);
        for(int i=1;i<=n;++i)
        {
            int x,y,z;
            scanf("%d%d%d",&x,&y,&z);
            pos[i].x=x;
            pos[i].y=y;
            pos[i].z=z;
        }
        for(int i=1;i<=n;++i)
            FatherOf[i]=i;
        for(int i=1;i<=n;++i)
            for(int j=i+1;j<=n;++j)
                if(dist(pos[i],pos[j])<=r*2.0)
                {
                    ancx=GetA(i);
                    ancy=GetA(j);
                    FatherOf[ancy]=ancx;
                }
        bool f=false,yes=false;
        for(int i=1;i<=n;++i)
            for(int j=i+1;j<=n;++j)
            {
                ancx=GetA(i);
                ancy=GetA(j);
                //printf(">>> anc X:%d, anc Y:%d; pos i:%d, pos j:%d\n",ancx,ancy,i,j);
                f=false;
                if(pos[i].z<=pos[j].z)
                {
                    if(pos[i].z-r<=0 && h-pos[j].z-r<=0)
                        f=true;
                }
                else
                    if(pos[j].z-r<=0 && h-pos[i].z-r<=0)
                        f=true;
                if(ancx==ancy && f)
                {
                    yes=true;
                    break;
                }
            }
        if(yes)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}