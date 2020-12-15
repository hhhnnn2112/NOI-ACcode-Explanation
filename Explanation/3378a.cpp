#include<cstdio>
#include<queue>

using namespace std;

const int N=1000005;

//priority_queue <int> q; //大根堆
priority_queue <int,vector <int>,greater <int> > q; //小根堆
int n;

int main()
{
    scanf("%d",&n);
    while(n--)
    {
        int t;
        scanf("%d",&t);
        if(t==1)
        {
            int k;
            scanf("%d",&k);
            q.push(k);
        }
        else if(t==2)
            printf("%d\n",q.top());
        else if(t==3)
            q.pop();
    }
    return 0;
}