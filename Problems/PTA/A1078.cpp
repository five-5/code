#include <cstdio>
#include <cmath>

const int N = 10007;
bool hash_table[N] = {false};

bool isPrime(int num)
{
    if (num <= 1) return false;
    for (int i = 2; i <= std::sqrt(num); ++i)
    {
        if (num % i == 0) return false;
    }

    return true;
}

int main()
{
    int msize, n, tmp;
    scanf("%d %d", &msize, &n);

    // 找到 >= msize 最小的素数
    while(isPrime(msize) == false)
    {
        ++msize;
    }

    for (int i = 0; i < n ; ++i)
    {
        scanf("%d", &tmp);
        // 二次方探测
        int index = tmp % msize;
        if (hash_table[index] == false)
        {
            hash_table[index] = true;
            if (i > 0) printf(" ");
            printf("%d", index);
        }
        else
        {
            int step; // 二次方探查法步长
            for (step = 1; step < msize; ++step)
            {
                index = (tmp + step * step) % msize;
                if (hash_table[index] == false)
                {
                    hash_table[index] = true;
                    if (i > 0) printf(" ");
                    printf("%d", index);
                    break;
                }
            }
            // 未找到插入的地方
            if (step >= msize)
            {
                if (i > 0) printf(" ");
                printf("-");
            }
        }
    }

    return 0;
}
