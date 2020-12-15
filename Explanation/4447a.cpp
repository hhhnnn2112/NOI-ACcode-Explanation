#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>

const int N=100005;

int n,a[N];
int f[N],s[N]; //f[i]: 第i组内最大值; s[i]: 第i组个数
int l,r,mid,cnt;

using namespace std;

inline void find() {
    cnt=1;
    f[cnt]=a[cnt]+1;
    s[cnt]=1;
    for(int i=2;i<=n;++i) {
        l=1;
        r=cnt;
        while(l<r) {
            mid=(l+r+1)/2;
            if(f[mid]>a[i])
                r=mid-1;
            else
                l=mid;
        }
        if(f[l]==a[i]) {
            f[l]=a[i]+1;
            ++s[l];
        } else {
            ++cnt;
            f[cnt]=a[i]+1;
            ++s[cnt];
        }
    }
    return ;
}

int main() {
    scanf("%d",&n);
    for(register int i=1;i<=n;++i) scanf("%d",&a[i]);
    sort(a+1,a+n+1);
    find();
    int ans=1<<29;
    for(int i=1;i<=cnt;++i)
        if(ans>s[i])
            ans=s[i];
    printf("%d\n",ans);
    return 0;
}