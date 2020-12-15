#pragma GCC optimize(3)
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>

using namespace std;

const int N=100005;

int n,a[N];

int main()
{
    scanf("%d",&n);
    for(register int i=1;i<=n;++i)
        scanf("%d",&a[i]);
    sort(a+1,a+n+1);
    for(register int i=1;i<=(n+1)/2;++i)
    {
        int k=2*i-1;
        printf("%d\n",a[k/2+1]);
    }
    /*
    if(n%2==0)
        printf("%d\n",(a[n/2]+a[n/2+1])/2);
    else
        printf("%d\n",a[n/2+1]);
    */
    return 0;
}