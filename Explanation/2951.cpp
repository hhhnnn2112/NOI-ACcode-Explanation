#include<cstdio>
#include<vector>
#include<queue>

using namespace std;

const int N=20005,M=50005;

struct node
{
    int next,len;
}p;

vector <node> v[N];
queue <int> q;

int n,m;

int dis[N],t;
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

    int maxi=0,point=0;
    for(int i=1;i<=n;++i)
        if(dis[i] > maxi)
        {
            maxi=dis[i];
            point=i;
        }
    int tot=0;
    for(int i=1;i<=n;++i)
        if(dis[i] == maxi)
            ++tot;
    printf("%d %d %d\n",point,maxi,tot);
    return 0;
}