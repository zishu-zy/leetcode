
#include "data_define.h"

class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        int i = 0;
        int j = 0;
        vector<int> vecTemp(m + n, 0);
        int nCount = 0;
        while (i < m && j < n) {
            if (nums1[i] < nums2[j]) {
                vecTemp[nCount++] = nums1[i];
                ++i;
            } else {
                vecTemp[nCount++] = nums2[j];
                ++j;
            }
        }
        for (; i < m; i++) {
            vecTemp[nCount++] = nums1[i];
        }
        for (; j < n; j++) {
            vecTemp[nCount++] = nums2[j];
        }
        nums1.swap(vecTemp);
    }
};

TEST(Solution, leetcode)
{
    vector<int> input_1;
    vector<int> input_2;
    vector<int> output;
    vector<int> expected;

    input_1 = {1, 2, 3, 0, 0, 0};
    input_2 = {2, 5, 6};
    output = input_1;
    expected = {1, 2, 2, 3, 5, 6};
    Solution().merge(output, 3, input_2, 3);
    EXPECT_TRUE(output == expected)
        << "\ninput:   " << getString(input_1) << "\n         " << getString(input_2)
        << "\nouput:   " << getString(output) << "\nexpected:" << getString(expected);

    input_1 = {1};
    input_2 = {};
    output = input_1;
    expected = {1};
    Solution().merge(output, 1, input_2, 0);
    EXPECT_TRUE(output == expected)
        << "\ninput:   " << getString(input_1) << "\n         " << getString(input_2)
        << "\nouput:   " << getString(output) << "\nexpected:" << getString(expected);
}

int main(int argc, char *argv[])
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
