#include<cstdio>

using namespace std;

const double error=0.0000001;

double power(int p,double x)
{
    double ans=1.0;
    for(int i=1;i<=p;++i)
        ans*=x;
    return ans;
}

double f(double x)
{
    return power(5,x)-15*power(4,x)+85*power(3,x)-225*power(2,x)+274*x-121;
}

double l,r;

int main()
{
    l=1.50;
    r=2.40;
    while(l<r-error)
    {
        //printf(">>%.8lf %.8lf",l,r);
        double mid=(l+r)/2.0;
        if(f(mid)>0)
            l=mid;
        else if(f(mid)<0)
            r=mid;
    }
    printf("%.6lf\n",l);
    return 0;
}