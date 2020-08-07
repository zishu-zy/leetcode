
#include "data_define.h"

class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        int i = 0;
        int nStart = 0;
        int nEnd = nums.size() - 1;
        while (i <= nEnd) {
            if (nums[i] == 2) {
                swap(nums[i], nums[nEnd]);
                --nEnd;
            } else if (nums[i] == 0 && i != nStart) {
                swap(nums[i], nums[nStart]);
                ++nStart;
            } else {
                ++i;
            }
        }
    }
};

TEST(Solution, leetcode)
{
    std::vector<int> vecInput;
    std::vector<int> vecOutput;
    std::vector<int> vecExpected;

    vecInput = {2, 0, 1};
    vecOutput = vecInput;
    Solution().sortColors(vecOutput);
    vecExpected = {0, 1, 2};
    EXPECT_TRUE(vecOutput == vecExpected)
        << "\ninput:   " << getString(vecInput) << "\nouput:   " << getString(vecOutput)
        << "\nexpected:" << getString(vecOutput);

    vecInput = {2, 0, 2, 1, 1, 0};
    vecOutput = vecInput;
    Solution().sortColors(vecOutput);
    vecExpected = {0, 0, 1, 1, 2, 2};
    EXPECT_TRUE(vecOutput == vecExpected)
        << "\ninput:   " << getString(vecInput) << "\nouput:   " << getString(vecOutput)
        << "\nexpected:" << getString(vecOutput);
}

int main(int argc, char *argv[])
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
