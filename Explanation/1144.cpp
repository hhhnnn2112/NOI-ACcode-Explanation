#include<cstdio>
#include<queue>
#include<vector>

using namespace std;

const int N=1000005,mod=100003;

struct node
{
    int next,len;
}p;

vector <node> v[N];
queue <int> q;

int n,m;

int dis[N],t;
int ways[N];
bool f[N];

void spfa(int s)
{
    for(int i=1;i<=n;++i)
        dis[i]=1<<29;
    dis[s]=0;
    f[s]=true;
    ways[1]=1;
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
                ways[nextnum]=ways[t];
                if(!f[nextnum])
                {
                    f[nextnum]=true;
                    q.push(nextnum);
                }
            }
            else if(dis[nextnum] == dis[t]+nextlen)
            {
                ways[nextnum]=(ways[nextnum]%mod+ways[t]%mod)%mod;
            }
        }
    }
}

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;++i)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        p.next=y;
        p.len=1;
        v[x].push_back(p);
        p.next=x;
        v[y].push_back(p);
    }
    spfa(1);
    for(int i=1;i<=n;++i)
        printf("%d\n",ways[i]%mod);
    return 0;
}