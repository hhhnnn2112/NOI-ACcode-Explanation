#include<cstdio>
#include<queue>
#include<vector>

using namespace std;

const int N=2005,M=100005;

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

            if(dis[nextnum]*1.0<dis[t]*nextlen*1.0)
            {
                dis[nextnum]=dis[t]*nextlen*1.0;
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
        int x,y,percent;
        scanf("%d%d%d",&x,&y,&percent);
        p.next=y;
        p.len=percent/100.0;
        v[x].push_back(p);
        p.next=x;
        v[y].push_back(p);
    }
    scanf("%d%d",&a,&b);
    spfa(a);
    printf("%.8lf\n",100.0/dis[b]);
    return 0;
}