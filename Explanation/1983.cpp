#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<vector>
#include<queue>

using namespace std;

const int N=1005;

vector <int> link[N];
queue <int> q;

int n,m;
bool vis[N][N];
int station[N],nowpos[N];
int level[N],indegree[N];

void Tsort()
{
    for(int i=1;i<=n;++i)
    {
		if(!indegree[i])
			q.push(i);
        level[i]=1;
    }
    
    while(!q.empty())
    {
        int t=q.front();
        q.pop();

        for(int i=0;i<link[t].size();++i)
        {
			int v=link[t][i];
			--indegree[v];
            if(level[v]<level[t]+1)
                level[v]=level[t]+1;
			if(!indegree[v])
				q.push(v);
		}
    }
}

int main()
{
    scanf("%d%d",&n,&m);
    while(m--)
    {
        int t;
        scanf("%d",&t);
        memset(nowpos,false,sizeof(nowpos));
        for(int i=1;i<=t;++i)
        {
            scanf("%d",&station[i]);
            nowpos[station[i]]=true;
        }
        for(int i=station[1]+1;i<station[t];++i)
        {
            if(nowpos[i])
                continue;
            for(int j=1;j<=t;++j)
            {
				int u=station[j];
				if(!vis[u][i])
                {
					vis[u][i]=true;
					link[i].push_back(u);
					++indegree[u];
				}
            }    
        }
    }

    Tsort();

    int ans=0;
	for(int i=1;i<=n;++i)
		ans=max(ans,level[i]);
	printf("%d\n",ans);
    return 0;
}