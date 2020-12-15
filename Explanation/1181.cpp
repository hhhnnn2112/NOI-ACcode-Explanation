#include<iostream>

using namespace std;

int n,m,k,ans=1;

int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;++i)
    {
        int a;
        cin>>a;
        if(k+a<=m)
        {
            k+=a;
        }
        else
        {
            ++ans;
            k=a;
        }
    }
    cout<<ans<<"\n";
    return 0;
}