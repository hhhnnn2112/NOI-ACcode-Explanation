#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>

typedef long long int;

using namespace std;

const int N=500005;

struct node
{
    int x,y,len;
}ar[N];

int a,b,cnt;
int FatherOf[N];
int ans;

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
    scanf("%d%d",&a,&b);
    for(int i=1;i<=b;++i)
        FatherOf[i]=i;
    for(int i=1;i<=b;++i)
        for(int j=1;j<=b;++j)
        {
            int t;
            scanf("%d",&t);
            if(i<=j && t)
            {
                ++cnt;
                ar[cnt].len=min(a,t);
                ar[cnt].x=i;
                ar[cnt].y=j;
            }
        }
    sort(ar+1,ar+cnt+1,cmp);
    for(int i=1;i<=cnt;++i)
    {
        int ancx=GetA(ar[i].x);
        int ancy=GetA(ar[i].y);
        if(ancx!=ancy)
        {
            FatherOf[ancy]=ancx;
            if(ar[i].len<a)
                ans+=ar[i].len;
            else
                ans+=a;
        }
    }
    printf("%d\n",ans+a);
    return 0;
}