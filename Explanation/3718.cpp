#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>

using namespace std;

const int N=100005;

int n,k,ans;
int l=2,r,mid;
bool a[N];
char c[N];

inline bool Find()
{
    int tot=0,cnt=1;
    bool t=a[1];
    //第一个点强制不改
    for(int i=2;i<=n;++i)
    {
        if(a[i]==t)
            ++cnt; //cnt记录同类型个数
        else
        {
            cnt=1;
            t=!t;
        }
        if(cnt>mid)
        {
            ++tot;
            cnt=1;
            t=!t;
        }
    }
    int tott=1;
    cnt=1;
    if(a[1])
        t=0;
    else
        t=1;
    //第一个点强制改
    for(int i=2;i<=n;++i)
    {
        if(a[i]==t)
            ++cnt; //cnt记录同类型个数
        else
        {
            cnt=1;
            t=!t;
        }
        if(cnt>mid)
        {
            ++tott;
            cnt=1;
            t=!t;
        }
    }
    if(min(tot,tott)<=k)
        return true;
    else
        return false;
}

int main()
{
    scanf("%d%d",&n,&k);
    r=n;
    scanf("%s",c);
    int p=0;
    for(int i=0;i<n;++i)
    {
        if(i%2==0 && c[i]=='N')
            ++p;
        if(i%2==1 && c[i]=='F')
            ++p;
    }
    if(p<=k || n-p<=k) {
        printf("1\n");
        return 0;
    }
    for(int i=0;i<n;++i)
        if(c[i]=='N')
            a[i+1]=true;
    while(l<=r)
    {
        mid=(l+r)/2; //mid二分不优美度
        if(Find())
        {
            r=mid-1;
            ans=mid;
        }
        else
            l=mid+1;
    }
    printf("%d\n",ans);
    return 0;
}