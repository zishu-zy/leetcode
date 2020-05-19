
#include "data_define.h"

class Solution
{
public:
    bool isMatchHelper(string &s, string &p, int n_s_start, int n_p_start)
    {
        bool bRet = true;
        int nSLen = s.size();
        int nPLen = p.size();
        int i = n_s_start, j = n_p_start;
        while (i < nSLen && j < nPLen) {
            if (p.at(j) == '*') {
                if (j == nPLen - 1) {
                    i = nSLen;
                    j = nPLen;
                    break;
                } else {
                    if (i == nSLen - 1) {
                        if (p.at(j + 1) == '?' || p.at(j + 1) == s.at(i)) {
                            i = nSLen;
                            j = nPLen;
                            break;
                        } else {
                            i = 0;
                            j = 0;
                            break;
                        }
                    } else {
                        if (p.at(j + 1) == s.at(i)) {
                            bool bTmp = isMatchHelper(s, p, i + 1, j);
                            if (bTmp) {
                                i = nSLen;
                                j = nPLen;
                                break;
                            }
                            ++i;
                            j += 2;
                        } else {
                            ++i;
                        }
                    }
                }
            } else if (p.at(j) == '?') {
                ++i, ++j;
                continue;
            } else {
                if (s.at(i) == p.at(j)) {
                    ++i, ++j;
                } else {
                    bRet = false;
                    break;
                }
            }
        }
        if (i == nSLen && j == nPLen) {
            bRet = true;
        } else {
            bRet = false;
        }
        return bRet;
    }
    bool isMatch(string s, string p) { return isMatchHelper(s, p, 0, 0); }
};

TEST(leetcode, isMatch)
{
    Solution s;
    EXPECT_FALSE(s.isMatch("ab", ".*c"));
    EXPECT_FALSE(s.isMatch("aa", "a"));
    EXPECT_TRUE(s.isMatch("aa", "a*"));
    EXPECT_TRUE(s.isMatch("aaa", "a*a"));
    EXPECT_TRUE(s.isMatch("ab", ".*"));
    EXPECT_TRUE(s.isMatch("aab", "c*a*b"));
    EXPECT_FALSE(s.isMatch("mississippi", "mis*is*p*."));
}

int main(int argc, char *argv[])
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
