#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>

using namespace std;

const int N=100005;

int n,m,a[N];

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;++i)
        scanf("%d",&a[i]);
    scanf("%d",&m);
    sort(a+1,a+n+1);
    for(int i=1;i<=n;++i)
    {
        int target=m-a[i],l=i+1,r=n;
        while(l<r)
        {
            int mid=(l+r)/2;
            if(a[mid]<target)
                l=mid+1;
            else
                r=mid;
        }
        if(a[l]==target)
        {
            printf("%d %d\n",a[i],target);
            return 0;
        }
    }
    printf("No\n");
    return 0;
}