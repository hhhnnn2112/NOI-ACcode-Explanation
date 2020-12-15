#include<cstdio>
#include<cstring>
#include<string>

using namespace std;

const int N=100005;

int n,k,ans;
int l=2,r,mid;
bool a[N];
char c[N];
char fn[2]={'F','N'};

inline bool Find()
{
    int tot=0,cnt=1;
    bool t=a[1];
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
    if(tot<=k)
        return true;
    else
        return false;
}

int main()
{
    scanf("%d%d",&n,&k);
    r=n+1;
    scanf("%s",c);
    int p=0;
    for(int i=0;i<n;++i)
        if(c[i]==c[i%2])
            ++p;
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