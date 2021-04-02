
#include "data_define.h"

class Solution
{
public:
    vector<int> grayCode(int n)
    {
        vector<int> vecRet;
        size_t nLen = pow(2, n);
        for (size_t i = 0; i < nLen; i++) {
            vecRet.push_back((i >> 1) ^ i);
        }

        return vecRet;
    }
};

TEST(Solution, leetcode)
{
    int input;
    vector<int> output;
    vector<int> expected;

    input = 2;
    output = Solution().grayCode(input);
    expected = {0, 1, 3, 2};

    EXPECT_TRUE(output == expected)
        << "\ninput:   " << getString(input) << "\nouput:   " << getString(output)
        << "\nexpected:" << getString(expected);
}

int main(int argc, char *argv[])
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
