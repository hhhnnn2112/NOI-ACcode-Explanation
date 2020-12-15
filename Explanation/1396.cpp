#include<cstdio>
#include<algorithm>
#include<cstring>

using namespace std;

const int N=20005;

struct node
{
    int x,y,len;
}g[N];

int n,m,s,t;
int FatherOf[N];

bool cmp(node a,node b)
{
    return a.len<b.len;
}

int GetA(int x)
{
    if(FatherOf[x]==x)
        return x;
    else
        return FatherOf[x]=GetA(FatherOf[x]);
}

int main()
{
    scanf("%d%d%d%d",&n,&m,&s,&t);
    for(int i=1;i<=n;++i)
        FatherOf[i]=i;
    for(int i=1;i<=m;++i)
        scanf("%d%d%d",&g[i].x,&g[i].y,&g[i].len);
    sort(g+1,g+m+1,cmp);
    for(int i=1;i<=m;++i)
    {
        int ancx=GetA(g[i].x);
        int ancy=GetA(g[i].y);
        if(ancx!=ancy)
            FatherOf[ancy]=ancx;
        if(GetA(s)==GetA(t))
        {
            printf("%d\n",g[i].len);
            return 0;
        }
    }
    return 0;
}