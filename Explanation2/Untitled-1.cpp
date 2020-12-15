#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;

int p;
int dis[60][60];

int k(char c)
{
    if(c>='a' && c<='z')
        return c-'a'+26;
    else
        return c-'A';
}

int main()
{
    memset(dis,127,sizeof(dis));
    scanf("%d",&p);
    while(p--)
    {
        char a,b;
        int c;
        cin>>a>>b>>c;
        dis[k(a)][k(b)]=min(dis[k(a)][k(b)],c);
        dis[k(b)][k(a)]=min(dis[k(b)][k(a)],c);
    }
    for(int k=0;k<60;k++)
        for(int i=0;i<60;i++)
            for(int j=0;j<60;j++)
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
    char ans;
    int mini=1<<30;
    for(int i=0;i<25;++i)
        if(dis[i][25]<=mini)
        {
            mini=dis[i][25];
            ans=i+'A';
        }
    cout<<ans<<" "<<mini<<endl;
    return 0;
}
/*

#include<cstdio>
#include<iostream>

using namespace std;

const int N=10005;

int f[N][N];
bool Q[N];
int p;

int main()
{
    scanf("%d",&p);
    memset(f,127,sizeof(f));
    for(int i=1;i<=p;++i)
    {
        char a,b;
        int c;
        cin>>a>>b>>c;
        f[a][b]=f[b][a]=min(f[a][b],c);
        if(a>='A' && a<='Z')
            Q[(int)a]=true;
        if(b>='A' && b<='Z')
            Q[(int)b]=true;
    }
    Q[(int)'Z']=false;
    for(int k=1;k<=p;++k)
        for(int i=1;i<=p;++i)
            for(int j=1;j<=p;++j)
                if(f[i][j] > f[i][k]+f[k][j])
                    f[i][j]=f[i][k]+f[k][j];
    char ans;
    int len=1<<30;
    for(int i=1;i<=26;++i)
        if(Q[i] && f[(int)'Z'][i] < len)
        {
            len=f[i][(int)'Z'];
            ans=i;
        }
    cout<<ans<<' '<<len<<endl;
    return 0;
}

*/


/*
    A ~ Z : 1 ~ 26
    a ~ z : 27 ~ 52


#include<cstdio>
#include<iostream>
#include<queue>
#include<vector>
#include<string>

using namespace std;

const int N=105;

struct node
{
    int next,len;
};

vector <node> v[N];
queue <int> q;

int p;
int dis[N],t;
bool f[N];

void spfa(int s)
{
    dis[s]=0;
    q.push(s);
    f[s]=true;

    while(!q.empty())
    {
        t=q.front();//当前位置在t
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
    ios::sync_with_stdio(false);
    scanf("%d",&p);
    for(int i=1;i<=p;++i)
            dis[i]=1<<29;
    for(int i=1;i<=p;++i)
    {
        char a,b;
        int c,x,y;
        cin>>a>>b>>c;
        if(a>='a' && a<='z')
            x=a-'a'+27;
        else
            x=a-'A'+1;
        if(b>='a' && b<='z')
            y=b-'a'+27;
        else
            y=b-'A'+1;
        node p;
        p.next=y;
        p.len=c;
        v[x].push_back(p);
        p.next=x;
        v[y].push_back(p);
    }

    spfa(26);

    int No,mini=1<<30;
    for(int i=1;i<=25;++i)
        if(dis[i]<mini)
        {
            mini=dis[i];
            No=i;
        }
    printf("%c %d\n",(char)mini+'A'-1,No);
    return 0;
}


*/