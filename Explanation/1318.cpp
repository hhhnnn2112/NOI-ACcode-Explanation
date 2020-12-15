#include<cstdio>
#define loop(A,s,e) for(int A=s;A<=e;++A)

using namespace std;

const int N=10005;

int n,a[N],l,r;

void init()
{
    l=1,r=n;
    while(!a[l])
        ++l;
    while(!a[r])
        --r;
    return ;
}

int main()
{
    scanf("%d",&n);
    loop(i,1,n)
        scanf("%d",&a[i]);
    init();
    return 0;
}