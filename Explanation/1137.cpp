#include<cstdio>
#include<vector>
#include<queue>

using namespace std;

const int N=100005;

struct node
{
    int next;
}p;

vector <node> v[N];
queue <int> q;

int n,m,dp[N];
int indegree[N],outdegree[N];
int t;

void Tsort()
{
    for(int i=1;i<=n;++i)
    {
        dp[i]=1;
        if(!indegree[i])
            q.push(i);
    }

    while(!q.empty())
    {
        t=q.front();
        q.pop();

        for(int i=0;i<v[t].size();++i)
        {
            int nextnum=v[t][i].next;
            --indegree[nextnum];
            dp[nextnum]=max(dp[nextnum],dp[t]+1);
            if(!indegree[nextnum])
                q.push(nextnum);
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
        v[x].push_back(p);
        ++outdegree[x];
        ++indegree[y];
    }

    Tsort();

    for(int i=1;i<=n;++i)
        printf("%d\n",dp[i]);
    return 0;
}