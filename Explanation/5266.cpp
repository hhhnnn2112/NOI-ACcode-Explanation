#include<cstdio>
#include<iostream>
#include<cstring>
#include<map>

using namespace std;

map <string,int> a;
int n,op;

int main() {
    scanf("%d",&n);
    while(n--) {
        scanf("%d",&op);
        string name;
        if(op!=4)
            cin>>name;
        if(op==1) {
            int s;
            scanf("%d",&s);
            a[name]=s;
            printf("OK\n");
        } else if(op==2) {
            if(a.count(name))
                printf("%d\n",a[name]);
            else
                printf("Not found\n");
        } else if(op==3) {
            if(a.count(name)) {
                a.erase(name);
                printf("Deleted successfully\n");
            }
            else
                printf("Not found\n");
        } else
            cout<<a.size()<<endl;
    }
    return 0;
}