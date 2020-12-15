#include<cstdio>
#define lowbit(x) (x&(-x))

using namespace std;

const int N=100005,INF=1<<30;

int m,n,c[N],a[N];

inline void Update(int id,int k) {
    while(id<=n) {
        c[id]+=k;
        id+=lowbit(id);
    }
    return ;
}

inline int min(int a,int b) {
    return a<b?a:b;
}

inline int find(int x,int y) {
    int id=y,ans=INF;
    while(id>=x)
        if(id-lowbit(id)>x) {
            ans=min(ans,c[id]);
            id-=lowbit(id);
        }
        else {
            ans=min(ans,a[id]);
            --id;
        }
    return ans;
}

int main() {
    scanf("%d%d",&m,&n);
    for(int i=1;i<=m;++i) {
        scanf("%d",&a[i]);
        Update(i,a[i]);
    }
    while(n--) {
        int x,y;
        scanf("%d%d",&x,&y);
        printf("%d\n",find(x,y));
    }
    return 0;
}
