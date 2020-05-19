/*
 * ==============================================================
 *
 *       FileName: 0010.cpp
 *    Description: 正则表达式匹配
 *
 *         Author: zhaiyu, zishuzy@gmail.com
 *        Created: 2018-12-10 16:08:32
 *  Last Modified: 2018-12-12 21:07:21
 *
 *  Copyright (C) 2018 zhaiyu. All rights reserved.
 *
 * ==============================================================
 */

#include "data_define.h"

// 最快的
class Solution
{
public:
    bool isMatch(string s, string p)
    {
        s = " " + s; //防止该案例："" "c*"
        p = " " + p;
        int m = s.size();
        int n = p.size();
        bool dp[m + 1][n + 1];
        memset(dp, false, (m + 1) * (n + 1));
        dp[0][0] = true;
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (s[i - 1] == p[j - 1] || p[j - 1] == '.') {
                    dp[i][j] = dp[i - 1][j - 1];
                } else if (p[j - 1] == '*') {
                    if (s[i - 1] != p[j - 2] && p[j - 2] != '.')
                        dp[i][j] = dp[i][j - 2];
                    else {
                        dp[i][j] = dp[i][j - 1] || dp[i][j - 2] || dp[i - 1][j];
                    }
                }
            }
        }
        return dp[m][n];
    }
};

// 未进行路径记录
// class Solution
// {
// public:
//     bool helper(string &s, string &p, int n_s, int n_p)
//     {
//         int nSLen = s.size();
//         int nPLen = p.size();
//         int i = n_s;
//         int j = n_p;
//         bool bRet = false;
//         while (i < nSLen && j < nPLen) {
//             if (j + 1 < nPLen && p.at(j + 1) == '*') {
//                 bool bTmp = helper(s, p, i, j + 2); // 不进行匹配
//                 if (bTmp) {
//                     bRet = bTmp;
//                     break;
//                 }
//             }
//             if (s.at(i) == p.at(j) || p.at(j) == '.') {
//                 ++i;
//                 ++j;
//             } else if (p.at(j) == '*') {
//                 bool bTmp = helper(s, p, i, j + 1); // 不进行匹配
//                 if (bTmp) {
//                     bRet = bTmp;
//                     break;
//                 }
//                 if (p.at(j - 1) == s.at(i) || p.at(j - 1) == '.') {
//                     ++i;
//                     // ++j;
//                 } else {
//                     ++j;
//                 }
//             } else {
//                 if (j + 1 < nPLen && p.at(j + 1) == '*') {
//                     j += 2;
//                 } else {
//                     break;
//                 }
//             }
//         }
//         while (j < nPLen) {
//             if (p.at(j) == '*') {
//                 ++j;
//             } else if (j + 1 < nPLen && p.at(j + 1) == '*') {
//                 j += 2;
//             } else {
//                 break;
//             }
//         }
//         if (i == nSLen && j == nPLen) {
//             bRet = true;
//         }
//         return bRet;
//     }
//     bool isMatch(string s, string p) { return helper(s, p, 0, 0); }
// };

TEST(leetcode, isMatch)
{
    Solution s;
    EXPECT_TRUE(s.isMatch("", "c*c*"));
    EXPECT_TRUE(s.isMatch("bbbba", ".*a*a"));
    EXPECT_TRUE(s.isMatch("a", "ab*"));
    EXPECT_TRUE(s.isMatch("aaa", ".*"));
    EXPECT_FALSE(s.isMatch("aaba", "ab*a*c*a"));
    EXPECT_FALSE(s.isMatch("mississippi", "mis*is*p*."));
    EXPECT_FALSE(s.isMatch("ab", ".*c"));
    EXPECT_FALSE(s.isMatch("aa", "a"));
    EXPECT_TRUE(s.isMatch("aa", "a*"));
    EXPECT_TRUE(s.isMatch("aaa", "a*a"));
    EXPECT_TRUE(s.isMatch("ab", ".*"));
    EXPECT_TRUE(s.isMatch("aab", "c*a*b"));
}

int main(int argc, char *argv[])
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
