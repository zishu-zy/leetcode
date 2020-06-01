
#include "data_define.h"

// 最快的 - 逻辑一样，但是这个快
class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        int n = nums.size() - 1, m = nums[0];
        for (int i = 0; i < m + 1; i++) {
            m = max(nums[i] + i, m);
            if (m + 1 > n)
                return true;
        }
        return false;
    }
};

class Solution2
{
public:
    bool canJump(vector<int> &nums)
    {
        int nLen = nums.size();
        int nMax = 0;
        bool bRet = false;
        for (int i = 0; i < nLen && i <= nMax; ++i) {
            if (nums.at(i) + i > nMax) {
                nMax = nums.at(i) + i;
            }
            if (nMax >= nLen - 1) {
                bRet = true;
                break;
            }
        }
        return bRet;
    }
};

bool canJump(vector<int> &&nums)
{
    return Solution().canJump(nums);
}

TEST(Solution, leetcode)
{
    EXPECT_TRUE(canJump({2, 3, 1, 1, 4}));
    EXPECT_FALSE(canJump({3, 2, 1, 0, 4}));
}

int main(int argc, char *argv[])
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
