#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>

using namespace std;

const int N=100005;

int n,a[N],b[N],f[N],dp[N];
int l,r,mid,ans;

int main() {
    scanf("%d",&n);
    for(int i=1;i<=n;++i) {
        scanf("%d",&a[i]);
        f[a[i]]=i;
    }
    for(int i=1;i<=n;++i) scanf("%d",&b[i]);
    for(int i=1;i<=n;++i) b[i]=f[b[i]]; //,printf("%d ",b[i])
    for(int i=1;i<=n;++i) {
        if(b[i]>dp[ans]) {
            ++ans;
            dp[ans]=b[i];
        }
        else { //二分查找b数组下标
            int l=1,r=ans;
            while(l<r) {
                mid=(l+r)/2;
                if(dp[mid]>b[i])
                    r=mid;
                else
                    l=mid+1;
            }
            dp[l]=b[i];
        }
    }
    printf("%d\n",ans);
    return 0;
}