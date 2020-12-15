#include<cstdio>

using namespace std;

const int N=500005;

int n,m,a[N],c[N];

int lowbit(int k) {
    return k&(-k);
}

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
        scanf("%d",&a[i]);
        Update(i,a[i]);
    }
    while(m--) {
        int op;
        scanf("%d",&op);
        if(op==1) {
            int x,k;
            scanf("%d%d",&x,&k);
            Update(x,k);
        }
        else {
            int x,y;
            scanf("%d%d",&x,&y);
            printf("%d\n",Query(y)-Query(x-1));
        }
    }
    return 0;
}