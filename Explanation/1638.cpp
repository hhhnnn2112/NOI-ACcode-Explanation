#pragma GCC optimize(3)
#include<cstdio>
#include<queue>
#include<algorithm>
#include<cmath>
#include<cstring>

using namespace std;

const int N=1000005,M=2005;

int n,m,a[N],ansL,ansR,minL,minR;
int l=1,r,mid;
queue <int> q;
int vis[M];

inline int totalPainters()
{
    memset(vis,0,sizeof(vis));
    while(!q.empty())
        q.pop();
    int cnt=0;
    for(int i=1;i<=mid;++i)
    {
        if(!vis[a[i]])
            ++cnt;
        ++vis[a[i]];
        q.push(a[i]);
        if(cnt==m)
        {
            minL=1;
            minR=mid;
            return cnt;
        }
    }
    for(int i=mid+1;i<=n;++i)
    {
        int t=q.front();
        --vis[t];
        if(!vis[t])
            --cnt;
        q.pop();
        if(!vis[a[i]])
            ++cnt;
        ++vis[a[i]];
        q.push(a[i]);
        if(cnt==m)
        {
            minL=i-mid+1;
            minR=i;
            return cnt;
        }
    }
    return cnt;
}

int main()
{
    scanf("%d%d",&n,&m);
    r=n;
    for(int i=1;i<=n;++i)
        scanf("%d",&a[i]);
    while(l<=r)
    {
        mid=(l+r)/2;
        int cnt=totalPainters();
        if(cnt==m)
        {
            ansL=minL;
            ansR=minR;
            r=mid-1;
        }
        else
            l=mid+1;
    }
    printf("%d %d\n",ansL,ansR);
    return 0;
}