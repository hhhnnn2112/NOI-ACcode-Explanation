#include<cstdio>
#include<algorithm>
#include<cmath>

using namespace std;

long long n,m;

int main()
{
    scanf("%lld%lld",&n,&m);
    double p=pow(n,(double)1/m);
    printf("%lld\n",(long long)p);
    return 0;
}