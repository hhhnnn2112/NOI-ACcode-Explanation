#include<cstdio>
#include<algorithm>
#include<cstring>

using namespace std;

const int N=1000005;

int n,q,a[N],op;

int main()
{
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;++i)
        scanf("%d",&a[i]);
    sort(a+1,a+n+1);
    while(q--)
    {
        scanf("%d",&op);
        if(!op)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            a[x]=y;
        }
        else
        {
            int x[N],y[N],l1,r1,l2,r2,tot=0;
            scanf("%d%d%d%d",&l1,&r1,&l2,&r2);
            for(int i=l1;i<=r1;++i)
            {
                ++tot;
                x[tot]=a[i];
            }
            tot=0;
            for(int i=l2;i<=r2;++i)
            {
                ++tot;
                y[tot]=a[i];
            }
            sort(x+1,x+tot+1);
            sort(y+1,y+tot+1);
            int k=x[1]-y[1];
            bool f=true;
            for(int i=2;i<=tot;++i)
                if(x[i]-y[i]!=k)
                {
                    printf("NO\n");
                    f=false;
                    break;
                }
            if(f)
                printf("YES\n");
        }
    }
    return 0;
}