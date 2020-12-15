#include<cstdio>
#include<queue>
#include<cstring>
#include<algorithm>
#include<cmath>

using namespace std;

typedef long long ll;

const int N=100005;

priority_queue <ll> q;

ll n,a[N],b[N],ans[N];

int main()
{
    scanf("%lld",&n);
    for(int i=1;i<=n;++i)
        scanf("%lld",&a[i]);
    for(int i=1;i<=n;++i)
        scanf("%lld",&b[i]);
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j)
        {
            if(i==1) //仅当第一遍时
                q.push(a[i]+b[j]);
            else
            {
                ll t=a[i]+b[j];
                if(t<q.top())
                {
                    q.pop();
                    q.push(t);
                }
                else
                    break;
            }
        }
    ll cnt=0;
    //printf(">>> ");
    while(!q.empty())
    {
        ++cnt;
        ans[cnt]=q.top();
        //printf("%lld ",q.top());
        q.pop();
    }
    sort(ans+1,ans+cnt+1);
    for(int i=1;i<=n;++i)
        printf("%lld ",ans[i]);
    printf("\n");
    return 0;
}