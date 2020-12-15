#include<cstdio>
#include<cmath>
#include<algorithm>

using namespace std;

const int N=1000005;

int n,cnt;
int heap[N];

void Insert(int k)
{
    heap[cnt+1]=k;
    ++cnt;
    int pos=cnt;
    while(heap[pos]<heap[pos/2]&&pos!=1)
    {
        swap(heap[pos],heap[pos/2]);
        pos/=2;
    }
    return ;
}

int Query()
{
    return heap[1];
}

void Delete()
{
    heap[1]=heap[cnt];
    --cnt;
    int pos=1;
    while(pos*2<=cnt&&(heap[pos]>heap[pos*2]||heap[pos]>heap[pos*2+1]))
    {
        if(heap[pos*2]<=heap[pos*2+1])
        {
            swap(heap[pos],heap[pos*2]);
            pos*=2;
        }    
        else
        {
            swap(heap[pos],heap[pos*2+1]);
            pos*=2;
            ++pos;
        }    
    }
    return ;
}

int main()
{
    scanf("%d",&n);
    while(n--)
    {
        int op;
        scanf("%d",&op);
        if(op==1)
        {
            int num;
            scanf("%d",&num);
            Insert(num);
        }
        if(op==2)
            printf("%d\n",Query());
        if(op==3)
            Delete();
    }
    return 0;
}