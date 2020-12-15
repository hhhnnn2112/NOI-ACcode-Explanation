#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>

using namespace std;

const int N=50;
int n,tot,a[N];
bool f[3][N];
//f[0][i]代表这个点已经占用，f[1][i]和f[2][i]代表对角线占用情况。

void p(int k)
{
    if(k>n)
    {
        ++tot;
        if(tot<=3)
        {
            for(int i=1;i<=n;++i)
                cout<<a[i]<<' ';
            cout<<endl;
        }
        return;
    }
    for(int i=1;i<=n;++i)
        if((!f[0][i])&&(!f[1][i+k])&&(!f[2][k-i+n]))
        {//k-1层全部比较
            f[0][i]=f[1][i+k]=f[2][k-i+n]=1;
            a[k]=i;
            p(k+1);
            f[0][i]=f[1][i+k]=f[2][k-i+n]=0;
        }
}

int main()
{
    cin>>n;
    p(1);
    cout<<tot<<endl;
    return 0;
}
