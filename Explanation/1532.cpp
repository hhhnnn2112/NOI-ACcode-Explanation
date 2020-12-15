#pragma GCC optimize(2)
#pragma GCC optimize(3)
#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
typedef long long ll;

using namespace std;

const int N=10005;

ll a[N],n;
int cnt;
bool f;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    while(cin>>n)
    {
        f=true;
        cnt=1;
        a[cnt]=n;
        while(f)
        {
            ll num[15],bignum=0,smallnum=0,tot;
            while(n>0)
            {
                ++tot;
                num[tot]=n%10;
                n/=10;
            }
            sort(num+1,num+tot+1);
            for(int i=tot;i>=1;--i)
                bignum=bignum*10+num[i];
            for(int i=1;i<=tot;++i)
                smallnum=smallnum*10+num[i];
            ll sum=bignum-smallnum;
            for(int i=1;i<=cnt;++i)
                if(a[i]==n)
                {
                    f=false;
                    for(int j=i;j<=cnt;++j)
                        printf("%lld ",a[j]);
                    break;
                }
            ++cnt;
            a[cnt]=n;
        }
    }
    return 0;
}