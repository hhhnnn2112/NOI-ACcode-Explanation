#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<vector>
#define rg register
#define in inline

using namespace std;

vector<int> v;
int a,b,req,gcd;

in int getGcd(int a,int b) {
    return b>0 ? getGcd(b,a%b):a;
}

int main() {
    scanf("%d%d%d",&a,&b,&req);
    gcd=getGcd(a,b);
    for(rg int i=1;i<=int(sqrt(gcd));++i)
        if(gcd%i==0) {
            v.push_back(i);
            v.push_back(gcd/i);
        }
    sort(v.begin(),v.end());
    while(req--) {
        int x,y;
        scanf("%d%d",&x,&y);
        int pos=upper_bound(v.begin(),v.end(),y)-v.begin();
        if(v[pos-1]<x)
            printf("-1\n");
        else
            printf("%d\n",v[pos-1]);
    }
    return 0;
}