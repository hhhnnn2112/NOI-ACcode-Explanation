#include<cstdio>
#include<vector>
#include<queue>

#define ll long long

using namespace std;

const int N=500005;

struct node
{
    ll next,len;
}p;

//global
ll n,m,s;
vector <node> v[N];

//spfa
ll dis[N],t;
bool f[N];
queue <ll> q;

void spfa(ll s)
{
    dis[s]=0;
    q.push(s);
    f[s]=true;

    while(!q.empty())
    {
        t=q.front();//当前位置在t
        q.pop();
        f[t]=false;

        for(int i=0;i<v[t].size();++i)
        {
            ll nextnum=v[t][i].next;
            ll nextlen=v[t][i].len;

            if(dis[nextnum] > dis[t]+nextlen)
            {
                dis[nextnum]=dis[t]+nextlen;
                if(!f[nextnum])
                {
                    f[nextnum]=true;
                    q.push(nextnum);
                }
            }
        }
    }
}

int main()
{
    //input
    scanf("%lld%lld%lld",&n,&m,&s);
    for(int i=1;i<=m;++i)
    {
        ll u;
        scanf("%lld%lld%lld",&u,&p.next,&p.len);
        v[u].push_back(p);
    }
    
    //init
    for(int i=1;i<=n;++i)
        dis[i]=1<<29;
    
    //spfa
    spfa(s);

    //output
    for(int i=1;i<=n;++i)
        if(dis[i]==(1<<29))
            printf("2147483647 ");
        else
            printf("%lld ",dis[i]);
    printf("\n");
    return 0;
}