#include<cstdio>
#include<vector>
#include<queue>

using namespace std;

const int N=100005;

struct node
{
    int next,len;
}p;

struct dir
{
    int l,r;
}g[N];

vector <node> v[N];
queue <int> q;

int n,m,que;

int dis[N],t;
bool f[N];

void spfa(int s)
{
    for(int i=1;i<=n;++i)
        dis[i]=1<<29;
    dis[1]=g[1].r=0;
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
            int left=g[nextnum].l;
            int right=g[nextnum].r;

            g[nextnum].l=min(g[nextnum].l,g[t].r+1);
            g[nextnum].r=min(g[nextnum].r,g[t].l+1);

            if(g[nextnum].l!=left || g[nextnum].r!=right)
                q.push(nextnum);
        }
    }
}

int main()
{
    //input
    scanf("%d%d%d",&n,&m,&que);
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

    //init
    for(int i=1;i<=n;++i)
        g[i].l=g[i].r=1<<29;

    spfa(1);

    for(int i=1;i<=que;++i)
    {
        int a,l;
        scanf("%d%d",&a,&l);
        if(l%2==1 && g[a].l<=l)
            printf("Yes\n");
        else if(l%2==0 && g[a].r<=l)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}