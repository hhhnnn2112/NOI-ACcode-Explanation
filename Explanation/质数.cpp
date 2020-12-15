/**
一个大于1的自然数，如果除了1和它自身外，不能被其他自然数整除则称该数为质数。

例如7就是一个质数，因为它只能被1和7整除。

现在，给定你N个大于1的自然数，请你依次判断这些数是否是质数。

输入格式
第一行包含整数N，表示共有N个测试数据。

接下来N行，每行包含一个自然数X。

输出格式
每个测试用例输出一个结果，每个结果占一行。

如果测试数据是质数，则输出“X is prime”，其中X是测试数据。

如果测试数据不是质数，则输出“X is not prime”，其中X是测试数据。

#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
bool complare(int a,int b)
{
    return a>b;
}
int main()
{
   int n;
   cin>>n;
   int x, res = 0;
   while(n--){
       cin>> x;
       int k  = (int)(sqrt(x));
        bool prime = true;
       for(int i = 2; i <= k; i++){
           if(x % i == 0){
               prime = false;
           }
       }
       if(prime == true)
        cout<< x <<" is prime" << endl;
      if(prime == false)
          cout << x <<" is not prime" << endl;
   }
  return 0;
}

