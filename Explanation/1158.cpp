#include<cstdio>
typedef long long ll;

using namespace std;

const int N=100005;

struct node
{
    int x,y;
}w[N];

ll x1,y1,x2,y2,num,tarx[N],tary[N];
double dis[N];

inline ll read()
{
    char ch=getchar(); 
    int x=0,f=1;
    while(ch<'0'||ch>'9')
    {
        if(ch=='-')
            f=-1;
        ch=getchar();
    }
    while('0'<=ch&&ch<='9')
    {
        x=x*10+ch-'0';
        ch=getchar();
    }
    return x*f;
}

int main()
{
    scanf("%d%d%d%d%d",&x1,&y1,&x2,&y2,&num);
    for(register int i=1;i<=num;++i)
        scanf("%d%d",&w[i].x,&w[i].y);
    return 0;
}