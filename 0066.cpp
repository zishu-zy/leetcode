
#include "data_define.h"

class Solution
{
public:
    vector<int> plusOne(vector<int> &digits)
    {
        // std::vector<int> vecRet;
        int nCarry = 1;
        int nLen = digits.size();
        for (int i = nLen - 1; i >= 0; --i) {
            digits[i] += nCarry;
            if (digits[i] > 9) {
                nCarry = 1;
                digits[i] -= 10;
            } else {
                nCarry = 0;
                break;
            }
        }
        if (nCarry) {
            digits.insert(digits.begin(), 1);
        }
        return digits;
    }
};

vector<int> plusOne(vector<int> digits)
{
    return Solution().plusOne(digits);
}

TEST(Solution, leetcode)
{
    vector<int> vecInput;
    vector<int> vecOutput;
    vector<int> vecExpected;

    vecInput = {1, 2, 3};
    vecOutput = plusOne(vecInput);
    vecExpected = {1, 2, 4};
    EXPECT_TRUE(vecOutput == vecExpected)
        << "\ninput:" << getString(vecInput) << "\nouput:" << getString(vecOutput)
        << "\nexpected:" << getString(vecExpected);

    vecInput = {9, 9, 9};
    vecOutput = plusOne(vecInput);
    vecExpected = {1, 0, 0, 0};
    EXPECT_TRUE(vecOutput == vecExpected)
        << "\ninput:" << getString(vecInput) << "\nouput:" << getString(vecOutput)
        << "\nexpected:" << getString(vecExpected);
}

int main(int argc, char *argv[])
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
