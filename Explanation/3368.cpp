#include<cstdio>
#define lowbit(x) (x&(-x))

using namespace std;

const int N=500005;

int n,m,a[N],c[N],cur,p;

void Update(int id,int k) {
    while(id<=n) {
        c[id]+=k;
        id+=lowbit(id);
    }
    return ;
}

int Query(int id) {
    int ans=0;
    while(id>0) {
        ans+=c[id];
        id-=lowbit(id);
    }
    return ans;
}

int main() {
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i) {
        scanf("%d",&cur);
        Update(i,cur-p);
        p=cur;
    }
    while(m--) {
        int op;
        scanf("%d",&op);
        if(op==1) {
            int x,y,k;
            scanf("%d%d%d",&x,&y,&k);
            Update(x,k);
            Update(y+1,-k);
        }
        else {
            int x;
            scanf("%d",&x);
            printf("%d\n",Query(x));
        }
    }
    return 0;
}