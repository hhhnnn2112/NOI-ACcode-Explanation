#include<iostream>
#include<cstdio>
using namespace std;
#define N 500007
#define ll long long
#define ls (rt<<1)
#define rs ((rt<<1)|1)
#define mid (l+r>>1)
#define lson rt<<1,l,l+r>>1
#define rson rt<<1|1,(l+r>>1)+1,r
struct node
{
    int fa,l;
    ll num;
    node operator + (const node &b) const{//合并计算
        if(!b.fa&&!b.l)
		{
            return *this;
        }
        if(!fa&&!l)
		{
            return b;
        }
        node ans;
        if(l>b.fa)
		{
            ans.fa=fa;
            ans.l=l-b.fa+b.l;
            ans.num=((num>>b.fa)<<b.l)+b.num;
        }
        else
		{
            ans.fa=fa+b.fa-l;
            ans.l=b.l;
            ans.num=b.num;
        }
        return ans;
    }
}tree[N*5];
ll n,m,sz,now;
void build(int rt,int l,int r)
{
    if(l==r)
	{
		int x;
        scanf("%d",&x);
        if(x==1)
		{
            tree[rt].l=1;
        }
        else if(x==2)
		{
            tree[rt].l=1;
            tree[rt].num=1;
        }
        else
		{
            tree[rt].fa=1;
        }
        return;
    }
    build(lson);
    build(rson);
    tree[rt]=tree[ls]+tree[rs];
}
void upd(int rt,int l,int r,int pos,int x){//替换
    if(l==r)
	{
        tree[rt]=(node){0,0,0};
        if(x==1)
		{
            tree[rt].l=1;
        }
        else if(x==2)
		{
            tree[rt].l=1;
            tree[rt].num=1;
        }
        else
		{
            tree[rt].fa=1;
        }
        return;
    }
    if(pos>mid)
	{
        upd(rson,pos,x);
    }
    else
	{
        upd(lson,pos,x);
    }
    tree[rt]=tree[ls]+tree[rs];
}
node query(int rt,int l,int r,int s,int t){//查询
    node ans=(node){0,0,0},lans,rans;
    if(l>t||r<s)
	{
        return ans;
    }
    if(s<=l&&r<=t)
	{
        return tree[rt];
    }
    lans=query(lson,s,t);
    rans=query(rson,s,t);
    return lans+rans;
}

int main(){
    scanf("%d%d%d",&sz,&n,&m);
    build(1,1,n);
    int opt,x,y;
    ll s;
    node r;
    while(m--){
        scanf("%d",&opt);
        if(opt&1)
		{
            scanf("%lld%d%d",&s,&x,&y);
            r=query(1,1,n,x,y);

            s=(max(1ll,s>>r.fa)<<r.l)+r.num;
            printf("%lld",s),putchar('\n');
        }
        else
		{
            scanf("%d%d",&x,&y);
            upd(1,1,n,x,y);
        }
    }
    return 0;
}
