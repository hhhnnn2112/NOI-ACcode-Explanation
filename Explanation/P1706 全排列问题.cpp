#include<bits/stdc++.h>
using namespace std;
int n;
bool vis[15];
int step=1;
int a[15];
int main()
{
    if(step==1)
    {
//        freopen("pai.in","r",stdin);
//        freopen("pai.out","w",stdout);
        cin>>n;
    }
    int i;
    if(step-1==n)
    {
        for(i=1;i<=n;i++)
            printf("%5d",a[i]);
        printf("\n");
    }
    for(i=1;i<=n;i++)
    {
        if(vis[i]==0)
        {
            vis[i]=1;
            a[step]=i;
            step++;
            main();
            step--;
            vis[i]=0;
        }
    }
    return 0;
}