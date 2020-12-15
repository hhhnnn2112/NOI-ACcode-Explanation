#include<cstdio>
#include<queue>

using namespace std;

const int N=10005;

priority_queue <int,vector <int>,greater <int> > q;
int n;
int tot,cur;

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;++i)
    {
        int s;
        scanf("%d",&s);
        q.push(s);
    }
    while(!q.empty())
    {
        cur=q.top();
        q.pop();
        cur+=q.top();
        q.pop();
        if(!q.empty())
            q.push(cur);
        tot+=cur;
    }
    printf("%d\n",tot);
    return 0;
}