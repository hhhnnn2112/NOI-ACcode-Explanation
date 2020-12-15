#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>

const int N=100005;

int n,a[N],minn=1<<29;

using namespace std;

inline void find() {
    int cnt=1;
    for(int i=1;i<n;++i) {
        if(a[i]+1==a[i+1]) ++cnt;
        else {
            minn=min(minn,cnt);
            cnt=1;
        }
    }
}

int main() {
    scanf("%d",&n);
    for(register int i=1;i<=n;++i) scanf("%d",&a[i]);
    sort(a+1,a+n+1); //从小到大排列
    find();
    printf("%d\n",minn);
    return 0;
}

/*
4 5 2 3 -4 -3 -5
    -5 -4 -3 2 3 4 5
cnt: 1  2  3 1 2 3 4
*/