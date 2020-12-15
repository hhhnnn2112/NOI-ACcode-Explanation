#include<cstdio>
#include<vector>
#include<queue>
#include<algorithm>
#include<cstring>

using namespace std;

const int N=1005;

struct node
{
    int next,len;
}p;

vector <node> v1[N],v2[N];
queue <int> q;

int n,m;

bool f[N];
int dis1[N],dis2[N],t;

void spfa1(int s)
{
    for(int i=1;i<=n;++i)
        dis1[i]=1<<29;
    dis1[s]=0;
    f[s]=true;
    q.push(s);

    while(!q.empty())
    {
        t=q.front();
        q.pop();
        f[t]=false;

        for(int i=0;i<v1[t].size();++i)
        {
            int nextnum=v1[t][i].next;
            int nextlen=v1[t][i].len;
            if(dis1[nextnum] > dis1[t]+nextlen)
            {
                dis1[nextnum]=dis1[t]+nextlen;
                if(!f[nextnum])
                {
                    f[nextnum]=true;
                    q.push(nextnum);
                }
            }
        }
    }
}

void spfa2(int s)
{
    for(int i=1;i<=n;++i)
        dis2[i]=1<<29;
    dis2[s]=0;
    f[s]=true;
    q.push(s);

    while(!q.empty())
    {
        t=q.front();
        q.pop();
        f[t]=false;

        for(int i=0;i<v2[t].size();++i)
        {
            int nextnum=v2[t][i].next;
            int nextlen=v2[t][i].len;
            if(dis2[nextnum] > dis2[t]+nextlen)
            {
                dis2[nextnum]=dis2[t]+nextlen;
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
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        p.next=v;
        p.len=w;
        v1[u].push_back(p);//正向图
        p.next=u;
        v2[v].push_back(p);//反向图
    }

    spfa1(1);
    memset(f,false,sizeof(f));
    spfa2(1);

    int tot=0;
    for(int i=1;i<=n;++i)
    {
        tot+=dis1[i];
        tot+=dis2[i];
    }
    printf("%d\n",tot);
    return 0;
}