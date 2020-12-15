#include<cstdio>
#include<algorithm>

using namespace std;

typedef long long ll;

const int N=2005,M=100005;

ll n,m,cnt;
ll x,y,val;
ll FatherOf[N],ancx,ancy;
ll Ans;

struct node
{
    ll x,y,val;
}e[M];

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
    scanf("%lld%lld",&n,&m);
    for(ll i=1;i<=m;++i)
    {
        scanf("%lld%lld%lld",&x,&y,&val);
        e[i].x=x;
        e[i].y=y;
        e[i].val=val;
    }
    sort(e+1,e+m+1,cmp);
    for(ll i=1;i<=n;++i)
        FatherOf[i]=i;
    for(ll i=1;i<=m;++i)
    {
        ancx=GetA(e[i].x);
        ancy=GetA(e[i].y);
        if(ancx!=ancy)
        {
            FatherOf[ancy]=ancx;
            ++cnt;
            Ans=max(Ans,e[i].val);
            if(cnt==n-1)
                break;
        }
    }
    printf("%lld\n",Ans);
    return 0;
}