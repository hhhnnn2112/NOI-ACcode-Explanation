#include<cstdio>
#include<queue>
#include<cmath>
#include<algorithm>

using namespace std;

const int N=100005;

struct node
{
    int pos,tire; //pos位置，tire疲劳值
    bool operator <(const node &t) const
    {
        return tire<t.tire;
    }
}p,pleft,pright;

priority_queue <node> qleft,qright;
int n,dis[N],tire[N];

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;++i)
        scanf("%d",&dis[i]);
    for(int i=1;i<=n;++i)
        scanf("%d",&tire[i]);
    int bignum=0,bigpos=0;
    for(int i=1;i<=n;++i)
        if(2*dis[i]+tire[i]>bignum)
        {
            bignum=2*dis[i]+tire[i];
            bigpos=i;
        }
    printf("%d\n",bignum);

    for(int i=1;i<bigpos;++i)
    {
        p.pos=i;
        p.tire=tire[i];
        qleft.push(p);
    }
    for(int i=bigpos+1;i<=n;++i)
    {
        p.pos=i;
        p.tire=2*(dis[i]-bigpos)+tire[i];
        qright.push(p);
    }
    for(int i=1;i<n;++i)
    {
        if(!qleft.empty())
            pleft=qleft.top();
        else
        {
            pleft.pos=0;
            pleft.tire=0;
        }
        if(!qright.empty())
            pright=qright.top();
        else
        {
            pright.pos=0;
            pright.tire=0;
        }
        if(pleft.tire >= pright.tire)
        {
            bignum+=pleft.tire;
            qleft.pop();
        }    
        else
        {
            bignum+=pright.tire;
            for(int j=bigpos+1;j<pright.pos;++j)
            {
                p.pos=j;
                p.tire=tire[j];
                qleft.push(p);
            }
            bigpos=pright.pos;
            while(!qright.empty())
                qright.pop();
            for(int j=bigpos+1;j<=n;++j)
            {
                p.pos=i;
                p.tire=2*(dis[i]-bigpos)+tire[i];
                qright.push(p);
            }
        }
        printf("%d\n",bignum);
    }
    return 0;
}