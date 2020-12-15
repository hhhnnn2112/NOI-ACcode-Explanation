#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<algorithm>
#include<cmath>

using namespace std;

const int N=155,M=5005;

struct node
{
    int next,len;
}p;

struct edge
{
    int s,e;
}g[M];

struct answer
{
    int a,b;
}ans[M];

//global
int n,m;
int start,ends;
vector <node> v[N];
queue <int> q;

//spfa
int dis[N],t;
bool f[N];

void spfa(int s)
{
    //init
    for(int i=1;i<=n;++i)
        dis[i]=1<<29;
    dis[s]=0;
    f[s]=true;
    q.push(s);

    //spfa
    while(!q.empty())
    {
        t=q.front();
        q.pop();
        f[t]=false;
        
        for(int i=0;i<v[t].size();++i)
        {
            int nextnum=v[t][i].next;
            int nextlen=v[t][i].len;

            if((t==start && nextnum==ends) || (t==ends && nextnum==start))
                continue;
            
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

bool cmp(answer x,answer y)
{
    if(x.a != y.a)
        return x.a<y.a;
    else
        return x.b<y.b;
}

int main()
{
    //input
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;++i)
    {
        int x,y,len;
        scanf("%d%d",&x,&y);
        
        if(x>y)
            swap(x,y);

        g[i].s=x;
        g[i].e=y;

        p.next=x;
        p.len=1;
        v[y].push_back(p);
        p.next=y;
        v[x].push_back(p);
    }

    //spfa
    int cnt=0;
    for(int i=1;i<=m;++i)
    {
        start=g[i].s;
        ends=g[i].e;
        spfa(start);
        if(dis[ends]>=(1<<29))
        {
            ++cnt;
            ans[cnt].a=start;
            ans[cnt].b=ends;
        }
    }

    //sort
    sort(ans+1,ans+cnt+1,cmp);

    for(int i=1;i<=cnt;++i)
        printf("%d %d\n",ans[i].a,ans[i].b);
    return 0;
}