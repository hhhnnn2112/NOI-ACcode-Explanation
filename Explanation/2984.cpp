#include<cstdio>
#include<vector>
#include<queue>

using namespace std;

const int N=50005;

struct node
{
    int next,len;
}p;

//global
int n,m,b;
vector <node> v[N];

//spfa
queue <int> q;
bool f[N];
int dis[N],t;

void spfa(int s)
{
    for(int i=1;i<=n;++i)
        dis[i]=1<<29;
    dis[s]=0;
    f[s]=true;
    q.push(s);
    while(!q.empty())
    {
        t=q.front();
        q.pop();
        f[t]=false;

        for(int i=0;i<v[t].size();++i)
        {
            int nextnum=v[t][i].next;
            int nextlen=v[t][i].len;

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
    scanf("%d%d%d",&n,&m,&b);
    for(int i=1;i<=m;++i)
    {
        int x,y,w;
        scanf("%d%d%d",&x,&y,&w);
        p.next=y;
        p.len=w;
        v[x].push_back(p);
        p.next=x;
        v[y].push_back(p);
    }

    spfa(1);

    for(int i=1;i<=b;++i)
    {
        int s,e;
        scanf("%d%d",&s,&e);
        int ans=dis[s]+dis[e];
        printf("%d\n",ans);
    }
    return 0;
}