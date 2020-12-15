#include<cstdio>
#include<iostream>
#include<string>
typedef long long ll;

using namespace std;

const int N=5005;

string s;
ll n,len,yu,ans[N];

void division()
{
    ll cnt=0;
    for(int pos=0;pos<=len;++pos)
    {
        cnt=cnt*10+s[pos]-'0';
        if(cnt>=n)
        {
            ans[pos]=cnt/n;
            cnt%=n;
        }
        //printf(">>%lld ;yu: %lld\n",cnt,yu);
    }
    return ;
}

int main()
{
    cin>>s;
    scanf("%lld",&n);
    len=s.length()-1;
    division();
    int killZero=0;
    while(!ans[killZero])
        ++killZero;
    for(int i=killZero;i<=len;++i)
        printf("%lld",ans[i]);
    printf("\n");
    return 0;
}