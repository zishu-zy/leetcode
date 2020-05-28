
#include "data_define.h"

// 最快的 - 没啥区别啊
class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int sum = 0;
        int res = INT_MIN;
        for (int i = 0; i < nums.size(); ++i) {
            if (sum > 0)
                sum += nums[i];
            else
                sum = nums[i];
            res = max(res, sum);
        }
        return res;
    }
};

class Solution2
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int nLen = nums.size();
        if (nLen == 0)
            return 0;
        int nSum = 0;
        int nMax = nums.at(0);
        for (int i = 0; i < nLen; ++i) {
            nSum += nums.at(i);
            if (nSum > nMax) {
                nMax = nSum;
            }
            if (nSum < 0)
                nSum = 0;
        }
        return nMax;
    }
};

int maxSubArray(vector<int> &&nums)
{
    return Solution().maxSubArray(nums);
}

TEST(Solution, leetcode)
{
    EXPECT_EQ(maxSubArray({-2, 1, -3, 4, -1, 2, 1, -5, 4}), 6);
    EXPECT_EQ(maxSubArray({-2, 1}), 1);

    EXPECT_EQ(maxSubArray({-2, -1}), -1);
    EXPECT_EQ(maxSubArray({-1}), -1);
}

int main(int argc, char *argv[])
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
