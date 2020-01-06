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

    // �ҵ� >= msize ��С������
    while(isPrime(msize) == false)
    {
        ++msize;
    }

    for (int i = 0; i < n ; ++i)
    {
        scanf("%d", &tmp);
        // ���η�̽��
        int index = tmp % msize;
        if (hash_table[index] == false)
        {
            hash_table[index] = true;
            if (i > 0) printf(" ");
            printf("%d", index);
        }
        else
        {
            int step; // ���η�̽�鷨����
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
            // δ�ҵ�����ĵط�
            if (step >= msize)
            {
                if (i > 0) printf(" ");
                printf("-");
            }
        }
    }

    return 0;
}
