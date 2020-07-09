
#include "data_define.h"

class Solution
{
public:
    bool isNumber(string s)
    {
        s.erase(s.begin(), find_if(s.begin(), s.end(), [](int ch) { return !isspace(ch); }));
        s.erase(find_if(s.rbegin(), s.rend(), [](int ch) { return !isspace(ch); }).base(), s.end());
        int nLen = s.size();
        bool bSign = false;
        bool bPoint = false;
        bool bE = false;
        bool bRet = false;
        bool bLastNum = false;
        bool bHasNum = false;
        for (int i = 0; i < nLen; ++i) {
            if (s[i] >= '0' && s[i] <= '9') {
                bLastNum = true;
                bHasNum = true;
                bRet = true;
            } else if (s[i] == '+' || s[i] == '-') {
                if (bSign || bLastNum || bPoint) {
                    bRet = false;
                    break;
                } else {
                    bSign = true;
                    bLastNum = false;
                    bRet = false;
                }
            } else if (s[i] == '.') {
                if (bPoint || bE) {
                    bRet = false;
                    break;
                } else {
                    bPoint = true;
                    bLastNum = false;
                }
            } else if (s[i] == 'e') {
                if (bE || !bHasNum) {
                    bRet = false;
                    break;
                } else {
                    bRet = false;
                    bE = true;
                    bSign = false;
                    bPoint = false;
                    bLastNum = false;
                    bHasNum = false;
                }
            } else {
                bRet = false;
                break;
            }
        }
        return bRet;
    }
};

TEST(Solution, leetcode)
{
    EXPECT_EQ(Solution().isNumber("46.e3"), true);
    EXPECT_EQ(Solution().isNumber(".-4"), false);
    EXPECT_EQ(Solution().isNumber("6+1"), false);
    EXPECT_EQ(Solution().isNumber("3."), true);
    EXPECT_EQ(Solution().isNumber("3e3."), false);
    EXPECT_EQ(Solution().isNumber(".1"), true);
    EXPECT_EQ(Solution().isNumber("0"), true);
    EXPECT_EQ(Solution().isNumber(" 0.1"), true);
    EXPECT_EQ(Solution().isNumber("abc"), false);
    EXPECT_EQ(Solution().isNumber("1 a"), false);
    EXPECT_EQ(Solution().isNumber("2e10"), true);
    EXPECT_EQ(Solution().isNumber(" -90e3 "), true);
    EXPECT_EQ(Solution().isNumber(" 1e"), false);
    EXPECT_EQ(Solution().isNumber("e3"), false);
    EXPECT_EQ(Solution().isNumber(" 6e-1"), true);
    EXPECT_EQ(Solution().isNumber(" 99e2.5"), false);
    EXPECT_EQ(Solution().isNumber("53.5e93"), true);
    EXPECT_EQ(Solution().isNumber("--6"), false);
    EXPECT_EQ(Solution().isNumber("-+6"), false);
    EXPECT_EQ(Solution().isNumber("95a54e53"), false);
}

int main(int argc, char *argv[])
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
