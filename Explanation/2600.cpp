#include<cstdio>
#include<algorithm>
typedef long long ll;

using namespace std;
const int maxn=305;

int n;
double mid, ans=1e200;
double left,right,lmid,rmid;
double x[maxn],y[maxn],k[maxn],b[maxn];

double calc(double x,double y)
{
    double ans=0;
    for (int i=1;i<n;++i)
        ans=max(ans,x*k[i]+b[i]-y);
    return ans;
}

int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;++i)
        scanf("%lf",&x[i]);
    for (int i=1;i<=n;++i)
        scanf("%lf",&y[i]);
    for (int i=1;i<n;++i)
    {
        k[i]=(y[i+1]-y[i])/(x[i+1]-x[i]);
        b[i]=y[i]-x[i]*k[i];
    }
    for (int i=1;i<n;++i)
    {
        left=x[i];
        right=x[i+1];
        for(int t=100;t;--t)
        {
            lmid=left+(right-left)/3;
            rmid=right-(right-left)/3;
            if (calc(lmid,lmid*k[i]+b[i])<calc(rmid,rmid*k[i]+b[i]))
                right=rmid;
            else
                left=lmid;
        }
        mid=(left+right)/2;
        ans=min(ans,calc(mid,mid*k[i]+b[i]));
    }
    printf("%.3lf\n",ans);
    return 0;
}