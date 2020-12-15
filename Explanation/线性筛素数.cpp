//
// Created by 郑乃硕 on 2020/12/13.
//

题目背景
        本题已更新，从判断素数改为了查询第 kk 小的素数
        提示：如果你使用 cin 来读入，建议使用 std::ios::sync_with_stdio(0) 来加速。

题目描述
        如题，给定一个范围 n，有 q 个询问，每次输出第 k 小的素数。

输入格式
        第一行包含两个正整数 n,q，分别表示查询的范围和查询的个数。

接下来 q 行每行一个正整数 k，表示查询第 k 小的素数。

输出格式
        输出 q 行，每行一个正整数表示答案。








#include <cstdio>
#include <cstring>

bool isPrime[100000010];
//isPrime[i] == 1表示：i是素数
int Prime[6000010], cnt = 0;
//Prime存质数

void GetPrime(int n)//筛到n
{
    memset(isPrime, 1, sizeof(isPrime));
    //以“每个数都是素数”为初始状态，逐个删去
    isPrime[1] = 0;//1不是素数

    for(int i = 2; i <= n; i++)
    {
        if(isPrime[i])//没筛掉
            Prime[++cnt] = i; //i成为下一个素数

        for(int j = 1; j <= cnt && i*Prime[j] <= n/*不超上限*/; j++)
        {
            //从Prime[1]，即最小质数2开始，逐个枚举已知的质数，并期望Prime[j]是(i*Prime[j])的最小质因数
            //当然，i肯定比Prime[j]大，因为Prime[j]是在i之前得出的
            isPrime[i*Prime[j]] = 0;

            if(i % Prime[j] == 0)//i中也含有Prime[j]这个因子
                break; //重要步骤。见原理
        }
    }
}

int main()
{
    int n, q;
    scanf("%d %d", &n, &q);
    GetPrime(n);
    while (q--)
    {
        int k;
        scanf("%d", &k);
        printf("%d\n", Prime[k]);
    }
    return 0;
}