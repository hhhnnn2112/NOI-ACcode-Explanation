#include<cstdio>
#include<iostream>
#include<vector>
#include<queue>

using namespace std;

const int N=30;

struct node
{
    int next;
}p;

vector <node> v[N];
vector <int> ans;
queue <int> q;

int n,m,cnt,tot;
int indegree[N];
bool existed[N];
int dis[N];

int Tsort()
{
    int in[N],inCnt=0;
    bool twoIn=false;
    ans.clear();
    for(int i=1;i<=26;++i)
    {
        in[i]=indegree[i];
        if(!existed[i])
            continue;
        if(!in[i]&&inCnt==1)
            twoIn=true;
        if(!in[i])
        {
            q.push(i);
            ans.push_back(i);
            inCnt=1;
        }    
    }
    int c=0;

    while(!q.empty())
    {
        int t=q.front();
        ++c;
        q.pop();

        int degreecnt=0;
        for(int i=0;i<v[t].size();++i)
        {
            int nextnum=v[t][i].next;
            
            --in[nextnum];
            if(!in[nextnum])
            {
                ++degreecnt;
                q.push(nextnum);
                ans.push_back(nextnum);
            }    
        }
        if(degreecnt>1)
            twoIn=true;
    }
    if(c<cnt)
        return -1;
    else if(twoIn)
        return 0;
    else
        return 1;
}

int main()
{
    scanf("%d%d",&n,&m);
    while(m--)
    {
        ++tot;
        char x,y,fmt;
        int a,b;
        cin>>x>>fmt>>y;

        a=x-64;
        b=y-64;

        if(!existed[a])
        {
            ++cnt;
            existed[a]=true;
        }
        if(!existed[b])
        {
            ++cnt;
            existed[b]=true;
        }

        ++indegree[b];
        p.next=b;
        v[a].push_back(p);

        int sortAns=Tsort();

        if(sortAns==-1)
        {
            printf("Inconsistency found after %d relations.\n",tot);
            return 0;
        }    
        else if(sortAns==1 && cnt==n)
        {
            printf("Sorted sequence determined after %d relations: ",tot);
            for(int i=0;i<ans.size();++i)
                printf("%c",ans[i]+64);
            printf(".\n");
            return 0;
        }    
    }
    printf("Sorted sequence cannot be determined.\n");
    return 0;
}