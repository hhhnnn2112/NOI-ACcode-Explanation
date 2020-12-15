/**
输入整数N，求出斐波那契数列中的第N项是多少。

斐波那契数列的第0项是0，第1项是1，从第2项开始的每一项都等于前两项之和。

输入格式
第一行包含整数T，表示共有T个测试数据。

接下来T行，每行包含一个整数N。

输出格式
每个测试数据输出一个结果，每个结果占一行，

结果格式为“Fib(N) = x”，其中N为项数，x为第N项的值


 **/

using namespace std;

int main()
{
    int n;
    cin>>n;
    long long a[61];

    a[0]=0;
    a[1]=1;

    for (int i = 2; i <= 60; i++)
    {
        a[i]=a[i-1]+a[i-2];

    }
    while (n--)
    {
        int x;
        cin>>x;
        printf("Fib(%d) = %lld\n", x, a[x]);
    }
    return 0;
}