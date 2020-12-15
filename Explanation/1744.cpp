#include<cstdio>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

const int N=105,M=1005;

struct node
{
    int next;
    double len;
}p;

vector <node> v[N];
queue <int> q;

int n,m;
int s,e;
int posx[N],posy[N];

double dis[N];
int t;
bool f[N];

int area(int a)
{
    return a*a;
}

void spfa(int s)
{
    for(int i=1;i<=n;++i)
        dis[i]=1.0*(1<<29);
    dis[s]=0.0;
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
    scanf("%d",&n);
    for(int i=1;i<=n;++i)
        scanf("%d%d",&posx[i],&posy[i]);
    scanf("%d",&m);
    for(int i=1;i<=m;++i)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        double dist=1.0*sqrt(area(posx[x]-posx[y])+area(posy[x]-posy[y]));
        p.next=y;
        p.len=dist;
        v[x].push_back(p);
        p.next=x;
        v[y].push_back(p);
    }
    scanf("%d%d",&s,&e);
    spfa(s);
    printf("%.2lf\n",dis[e]);
    return 0;
}