#include <cstdio>
#include <vector>
#include <algorithm>
const int MAXN = 100001;
int nums[MAXN];
int leftMax[MAXN] = {-1};   // leftMax[i]: 记录从0-i-1最大的数
int main()
{
    int n, result;

    std::vector<int> ans;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d",&nums[i]);
    }

    int counter = 0;
    leftMax[0] = 0;   // 第一个数
    for (int i = 1; i < n; ++i)
    {
        if (nums[i-1] > leftMax[i-1])
            leftMax[i] = nums[i-1];
        else
            leftMax[i] = leftMax[i-1];
    }
    int rightMin = 1000000001;  // 记录从n-1~i+1最大的数
    for (int i = n - 1; i >= 0; --i)
    {
        if (rightMin > nums[i])
        {
            rightMin = nums[i];
            if (nums[i] > leftMax[i])
            {
                ++counter;
                ans.push_back(nums[i]);
            }
        }
    }

    printf("%d\n",counter);
    std::sort(ans.begin(), ans.end());
    if (counter > 0)
    {
        for (int i = 0; i < counter; ++i)
        {
            if (i >= 1)
                printf(" ");
            printf("%d", ans[i]);
        }
    }
    printf("\n");
    return 0;
}
