#include<cstdio>
#include<queue>
#include<vector>
 
using namespace std;

const int N=2005;

struct node
{
    int next;
    double len;
}p;

vector <node> v[N];

int n,m;
int s,e;

double d[N];
bool f[N];
int dis[N];
 
void spfa(int s)
{
    memset(dis,0,sizeof(dis));
    queue<int>q;
    q.push(s);
    dis[s]=1;
    f[s]=true;
    while(!q.empty())
    {
        int t=q.front();
        q.pop();
        f[t]=0;
        for(int i=0;i<v[t].size();++i)
        {
            int nextnum=v[t][i].next;
            if(dis[nextnum]<dis[t]*v[t][i].len)
            {
                dis[nextnum]=dis[t]*v[t][i].len;
                if(!f[nextnum])
                {
                    f[nextnum]=1;
                    q.push(nextnum);
                }
            }
        }
    }
 
}
 
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
    {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        p.next=b;
        p.len=(double)c/100.0;
        v[a].push_back(p);
        p.next=a;
        v[b].push_back(p);
    }
    scanf("%d%d",&s,&e);
    spfa(s);
    printf("%.8lf\n",100.0/dis[e]);
    return 0;
}
/*
#include<cstdio>
#include<vector>
#include<queue>

usf namespace std;

const int N=2005;

struct node
{
    int next;
    double len;
}p;

vector <node> v[N];
queue <int> q;

int n,m,a,b;
double dis[N];
int t;
bool f[N];

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
            double nextlen=v[t][i].len;

            if(dis[nextnum]>100.0/dis[t]/nextlen)
            {
                dis[nextnum]=dis[t]*nextlen;
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
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;++i)
    {
        int x,y,t;
        scanf("%d%d%d",&x,&y,&t);
        p.next=y;
        p.len=t/100.0;
        p.len=1-p.len;
        v[x].push_back(p);
        p.next=x;
        v[y].push_back(p);
    }
    scanf("%d%d",&a,&b);
    spfa(a);
    printf("%.8lf\n",100.0/dis[b]);
    return 0;
}
*/