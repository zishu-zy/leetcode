
#include "data_define.h"

class Solution
{
public:
    int numDecodings(string s)
    {
        int nLen = s.size();
        std::vector<int> vecResult(nLen + 2, 0);
        vecResult[nLen] = 1;
        int nResult = 0;
        bool bZeroFlag = false;
        for (int i = nLen - 1; i >= 0; --i) {
            vecResult[i] = vecResult[i + 1];
            if (s[i] == '0') {
                if (bZeroFlag) {
                    break;
                }
                vecResult[i] = 0;
                bZeroFlag = true;
            } else if (s[i] == '1') {
                bZeroFlag = false;
                vecResult[i] += vecResult[i + 2];
            } else if (s[i] == '2' && i != nLen - 1 && s[i + 1] < '7') {
                bZeroFlag = false;
                vecResult[i] += vecResult[i + 2];
            } else {
                if (bZeroFlag) {
                    break;
                }
                bZeroFlag = false;
            }
        }
        return bZeroFlag ? 0 : vecResult[0];
    }
};

TEST(Solution, leetcode)
{
    string input;
    int output;
    int expected;

    input = "27";
    output = Solution().numDecodings(input);
    expected = 1;
    EXPECT_TRUE(output == expected)
        << "\ninput:   " << getString(input) << "\nouput:   " << getString(output)
        << "\nexpected:" << getString(expected);

    input = "10";
    output = Solution().numDecodings(input);
    expected = 1;
    EXPECT_TRUE(output == expected)
        << "\ninput:   " << getString(input) << "\nouput:   " << getString(output)
        << "\nexpected:" << getString(expected);

    input = "131242";
    output = Solution().numDecodings(input);
    expected = 6;
    EXPECT_TRUE(output == expected)
        << "\ninput:   " << getString(input) << "\nouput:   " << getString(output)
        << "\nexpected:" << getString(expected);

    input = "12";
    output = Solution().numDecodings(input);
    expected = 2;
    EXPECT_TRUE(output == expected)
        << "\ninput:   " << getString(input) << "\nouput:   " << getString(output)
        << "\nexpected:" << getString(expected);

    input = "226";
    output = Solution().numDecodings(input);
    expected = 3;
    EXPECT_TRUE(output == expected)
        << "\ninput:   " << getString(input) << "\nouput:   " << getString(output)
        << "\nexpected:" << getString(expected);

    input = "06";
    output = Solution().numDecodings(input);
    expected = 0;
    EXPECT_TRUE(output == expected)
        << "\ninput:   " << getString(input) << "\nouput:   " << getString(output)
        << "\nexpected:" << getString(expected);
}

int main(int argc, char *argv[])
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
