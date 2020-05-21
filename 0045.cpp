
#include "data_define.h"

// 最快的
class Solution
{
public:
    int jump(vector<int> &nums)
    {
        int start = 0;
        int end = 1;
        int res = 0;
        int size = nums.size();
        int maxPos = 0;
        while (end < size) {
            for (int i = start; i < end; i++) {
                maxPos = max(maxPos, i + nums[i]);
            }
            start = end;
            end = maxPos + 1;
            res++;
        }
        return res;
    }
};

// class Solution
// {
// public:
//     int jump(vector<int> &nums)
//     {
//         int nLen = nums.size();
//         int nCount = 0;
//         int i = 0;
//         while (i < nLen - 1) {
//             int nMax = 0;
//             int nMaxIndex = i;
//             for (int j = i; j <= i + nums.at(i) && j < nLen; ++j) {
//                 if (nums.at(j) + j > nMax) {
//                     nMax = nums.at(j) + j;
//                     nMaxIndex = j;
//                 }
//                 if (nMax >= nLen -1) {
//                     break;
//                 }
//             }
//             nCount++;
//             if (nMaxIndex == i) {
//                 i = nMax;
//             } else {
//                 i = nMaxIndex;
//             }

//         }
//         return nCount;
//     }
// };

int jump(vector<int> &&nums)
{
    return Solution().jump(nums);
}

TEST(Solution, jump)
{
    EXPECT_EQ(jump(vector<int>{2, 3, 1}), 1);
    EXPECT_EQ(jump(vector<int>{3, 2, 1}), 1);
    EXPECT_EQ(jump(vector<int>{2, 3, 1, 1, 4}), 2);
    EXPECT_EQ(jump(vector<int>{0}), 0);
    EXPECT_EQ(jump(vector<int>{1, 0}), 1);
    EXPECT_EQ(jump(vector<int>{2, 3}), 1);
    EXPECT_EQ(jump(vector<int>{2, 3, 4}), 1);
}

int main(int argc, char *argv[])
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
