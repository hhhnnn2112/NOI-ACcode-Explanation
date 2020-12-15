#pragma GCC optimize(3)
#include<cstdio>

using namespace std;

const int N=100005;

int len,n,k,a[N],ans;
int l,r=10000005,mid;

inline bool find() {
    int cnt=0;
    for(int i=0;i<=n;++i) {
        if(a[i+1]-a[i]>mid) {
            cnt+=(a[i+1]-a[i])/mid;
            if((a[i+1]-a[i])%mid==0)
                --cnt;
        }
        if(cnt>k)
            return false;
    }
    return true;
}

int main() {
    scanf("%d%d%d",&len,&n,&k);
    for(int i=1;i<=n;++i) scanf("%d",&a[i]);
    a[n+1]=len;
    while(l<=r) {
        mid=(l+r)/2; //mid二分答案-最小“空旷指数”值
        bool f=find();
        if(f)
            r=mid-1;
        else {
            ans=mid;
            l=mid+1;
        }
    }
    printf("%d\n",l);
    return 0;
}