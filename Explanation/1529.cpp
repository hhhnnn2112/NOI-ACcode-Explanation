#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

const int N=55;

struct node
{
    int next,len;
}p;

int n;
vector <node> v[N];
queue <int> q;
bool existed[N];

bool f[N];
int dis[N],t;

void spfa(int start)
{
    for(int i=0;i<52;++i)
        dis[i]=1<<29;
    dis[start]=0;
    f[start]=true;
    q.push(start);
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
    scanf("%d",&n);
    for(int i=1;i<=n;++i)
    {
        char a,b;
        int c,x,y;
        cin>>a>>b>>c;
        if(a>='a' && a<='z')
            x=a-'a'+26;
        else
            x=a-'A';
        if(b>='a' && b<='z')
            y=b-'a'+26;
        else
            y=b-'A';
        
        existed[x]=existed[y]=true;

        p.next=x;
        p.len=c;
        v[y].push_back(p);
        p.next=y;
        v[x].push_back(p);
    }

    spfa(25);

    char c;
    int mini=1<<30;
    for(int i=0;i<25;++i)
        if(existed[i])
            if(dis[i]<mini)
            {
                mini=dis[i];
                c=i+'A';
            }
    cout<<c<<' '<<mini<<endl;
    return 0;
}

/*
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<string>

using namespace std;

const int N=10005;

int times;
int g[N][N],dis[N],low[N];
bool flag[N];
char t[N];

void add_Edge(int x,int y,int c)
{
    if(g[x][y]==0)
        g[x][y]=g[y][x]=c;
    else
        g[x][y]=g[y][x]=min(g[x][y],c);
    return ;
}

void dij(int start)
{
    int k=start;
    memset(low,127,sizeof(low));
    low[start]=0;
    int mint,p;
    for(int i=1;i<p;++i)
    {
        flag[k]=1;
        mint=1<<30;
        for(int j=1;j<=p;++j)
        {
            if(flag[j])
                continue;
            if(low[k]+g[k][j]<low[j])
                low[j]=low[k]+g[k][j];
            if(mint>low[j])
            {
                mint=low[j];
                p=j;
            }
        }
        k=p;
    }
}

int main()
{
    scanf("%d",&times);
    for(int i=1;i<=times;++i)
    {
        char a,b;
        int c,x,y;
        cin>>a>>b>>c;
        t[i]=a;
        if(a>='a' && a<='z')
            x=a-'a'+1;
        else
            x=a-'A'+27;
        if(b>='a' && b<='z')
            y=b-'a'+1;
        else
            y=b-'A'+27;
        add_Edge(x,y,c);
    }
    for(int i=1;i<=52;++i)
        dis[i]=g[i][52];
    dij(52);
    int mini=1<<30;
    char ans;
    for(int i=1;i<=times;++i)
        if(low[i]<mini)
        {
            mini=low[i];
            printf("> %d\n",mini);
            ans=t[i];
        }
    printf("%c\n",ans);
    return 0;
}
*/