
#include "data_define.h"

class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        if (nums.empty()) {
            return 0;
        }

        int nTmp = nums.at(0);
        bool bFlags = false;
        for (vector<int>::iterator it = nums.begin() + 1; it != nums.end();) {
            if (nTmp == *it) {
                if (bFlags) {
                    it = nums.erase(it);
                } else {
                    bFlags = true;
                    ++it;
                }
            } else {
                bFlags = false;
                nTmp = *it;
                ++it;
            }
        }
        return nums.size();
    }
};

TEST(Solution, leetcode)
{
    vector<int> input;
    vector<int> input_bk;
    int output;
    int expected;
    vector<int> expected_2;

    input = {0, 0, 1, 1, 1, 1, 2, 3, 3};
    input_bk = input;
    output = Solution().removeDuplicates(input);
    expected = 7;
    expected_2 = {0, 0, 1, 1, 2, 3, 3};
    EXPECT_TRUE(output == expected && input == expected_2)
        << "\ninput:   " << getString(input_bk) << "\nouput:   " << getString(output) << "\n"
        << getString(input) << "\nexpected:" << getString(expected) << "\n"
        << getString(expected_2);

    input = {1, 1, 1, 2, 2, 3};
    input_bk = input;
    output = Solution().removeDuplicates(input);
    expected = 5;
    expected_2 = {1, 1, 2, 2, 3};
    EXPECT_TRUE(output == expected && input == expected_2)
        << "\ninput:   " << getString(input_bk) << "\nouput:   " << getString(output) << "\n"
        << getString(input) << "\nexpected:" << getString(expected) << "\n"
        << getString(expected_2);
}

int main(int argc, char *argv[])
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
