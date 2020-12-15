#include<cstdio>
#include<cmath>
#include<algorithm>

using namespace std;

const int N=10005;

int n,m,a[N];

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i)
        scanf("%d",&a[i]);
    while(m--)
        next_permutation(a+1,a+n+1);
    for(int i=1;i<=n;++i)
        printf("%d ",a[i]);
    printf("\n");
    return 0;
}