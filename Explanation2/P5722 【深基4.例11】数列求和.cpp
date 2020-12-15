#include<bits/stdc++.h>
using namespace std;
int n,sum;
int main() {
    scanf("%d",&n);
    for(int i=1; i<=n; ++i) sum+=i;
    printf("%d\n",sum);
    return 0;
}
