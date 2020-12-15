#include<cstdio>
#include<queue>

typedef long long ll;

using namespace std;

priority_queue <ll> q;
ll n,m,lenadd,u,v,t,totadd;
double p;

int main()
{
    scanf("%lld%lld%lld%lld%lld%lld",&n,&m,&lenadd,&u,&v,&t);
    p=1.0*u/v;
    for(int i=1;i<=n;++i)
    {
        ll s;
        scanf("%lld",&s);
        q.push(s);
    }
    for(int i=1;i<=m;++i)
    {
        ll len=q.top();
        len+=lenadd*(i-1);
        q.pop();
        ll after1=ll(1.0*p*len);
        ll after2=len-after1;
        q.push(after1-lenadd*i);
        q.push(after2-lenadd*i);
        totadd+=lenadd;
        if(i%t==0)
            printf("%lld ",len);
    }
    printf("\n");
    for(int i=1;q.size();++i)
    {
        if(i%t==0)
            printf("%lld ",q.top()+totadd);
        q.pop();
    }
    printf("\n");
    return 0;
}