#include<cstdio>
#include<iostream>

typedef unsigned long long ll;

using namespace std;

ll rev_g(ll g)
{
    ll n=0;
    for(;g;g>>=1)
        n^=g;
    return n;
}

int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    printf("%lld\n",rev_g(k));
    return 0;
}