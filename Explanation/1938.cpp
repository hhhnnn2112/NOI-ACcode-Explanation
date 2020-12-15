#include<cstdio>
#include<vector>
#include<queue>

using namespace std;

const int N=225,M=155;

struct node
{
    int next,len;
}w;

vector <node> v[N];
queue <int> q;

int d,p,c,f,s;

int dis[N],t;
int times[N];
bool vis[N],returned;

void spfa(int s)
{
    for(int i=1;i<=c;++i)
        dis[i]=d;
    times[s]=1;
    vis[s]=true;
    q.push(s);

    while(!q.empty())
    {
        t=q.front();
        ++times[t];
        if(times[t]>c)
        {
            printf("-1\n");
            returned=true;
            return ;
        }
        q.pop();
        vis[t]=false;

        for(int i=0;i<v[t].size();++i)
        {
            int nextnum=v[t][i].next;
            int nextlen=v[t][i].len;

            if(dis[nextnum] < dis[t]-nextlen+d)
            {
                dis[nextnum]=dis[t]-nextlen+d;
                if(!vis[nextnum])
                {
                    vis[nextnum]=true;
                    q.push(nextnum);
                }
            }
        }
    }
}

int main()
{
    scanf("%d%d%d%d%d",&d,&p,&c,&f,&s);
    for(int i=1;i<=p;++i)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        w.next=y;
        v[x].push_back(w);
    }
    for(int i=1;i<=f;++i)
    {
        int x,y,val;
        scanf("%d%d%d",&x,&y,&val);
        w.next=y;
        w.len=val;
        v[x].push_back(w);
    }
    spfa(s);
    if(!returned)
    {
        int mini=0;
        for(int i=1;i<=c;++i)
            if(dis[i]>mini)
                mini=dis[i];
        printf("%d\n",mini);
    }
    return 0;
}