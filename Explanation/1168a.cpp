#include<cstdio>
#include<queue>

using namespace std;

const int N=100005;

priority_queue <int,vector<int>,greater<int> > smallheap;
priority_queue <int,vector<int>,less<int> > bigheap;
int n,t,ans[N];

int main() {
    scanf("%d",&n);
    for(int i=1;i<=n;++i) {
        scanf("%d",&t);
        if(bigheap.empty() || bigheap.top()>t)
            bigheap.push(t);
        else
            smallheap.push(t);
        int mid=(i+1)/2,size=bigheap.size();
        if(size>mid) {
            smallheap.push(bigheap.top());
            bigheap.pop();
        }
        if(size<mid) {
            bigheap.push(smallheap.top());
            smallheap.pop();
        }
        if(i%2)
            ans[mid]=bigheap.top();
    }
    for(int i=1;i<=(n+1)/2;++i)
        printf("%d\n",ans[i]);
    return 0;
}