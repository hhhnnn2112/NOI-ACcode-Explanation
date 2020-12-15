//
// Created by 郑乃硕 on 2020/12/15.
//

#include<bits/stdc++.h>
using namespace std;
int n,x;
long long sum=0;
int pd(int y) {
    for(int i=2; i*i<=y; ++i) {
        if(y%i==0) return 0;
    }
    return 1;
}
int main() {
    scanf("%d",&n);
    if(n<2) {
        printf("0\n");
        return 0;
    } else if(n==2) {
        printf("2\n1\n");
        return 0;
    }
    for(int i=2; i<=n; ++i) {
        if(i%2==0&&i!=2) continue;
        if(sum+i>n) {
            printf("%d\n",x);
            return 0;
        }
        if(pd(i)) {
            printf("%d\n",i);
            sum+=i;
            x++;
        }
    }
    return 0;
}
