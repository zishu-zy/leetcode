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

#include <algorithm>
#include <cassert>
#include <gtest/gtest.h>
#include <iostream>
#include <limits.h>
#include <sstream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

bool ismy(string &s, int se, string &p, int pe, vector<vector<int>> &dp)
{
    if (dp[se][pe] != 0) {
        return dp[se][pe];
    }
    if (p[pe] == '.') {
        dp[se][pe] = 1;
    }
    if (p[pe] == '*') {

    } else {
        if (s[se] == p[pe]) {
            if (se > 1 && pe > 1) {
                dp[se][pe] = ismy(s, se - 1, p, pe - 1, dp);
            } else {
                dp[se][pe] = 1;
            }
        } else {
            dp[se][pe] = -1;
        }
    }
    return dp[se][pe] == 1 ? true : false;
}

bool isMatch(string s, string p)
{
    int slen = s.size();
    int plen = p.size();
    int it_s = 0, it_p = 0;
    bool result = true;
    while (it_s < slen && it_p < plen) {
        if (p[it_p] == '.') {
            ++it_s;
            ++it_p;
        } else if (p[it_p] == '*') {
            if (p[it_p - 1] == '.' || p[it_p - 1] == s[it_s]) {
                ++it_s;
            } else {
                ++it_p;
            }
        } else if (s[it_s] == p[it_p]) {
            ++it_s;
            ++it_p;
        } else {
            if (it_p + 1 < plen) {
                if (p[it_p + 1] == '*') {
                    it_p += 2;
                    continue;
                }
            }
            result = false;
        }
    }
    if (it_s != slen) {
        result = false;
    }
    while (it_p < plen) {
        if (p[it_p] == '*') {
            it_p++;
        } else {
            if (it_p + 1 < plen) {
                if (p[it_p + 1] == '*') {
                    it_p += 2;
                    continue;
                }
            }
            result = false;
            break;
        }
    }
    return result;
}

TEST(leetcode0010, isMatch)
{
    EXPECT_FALSE(isMatch("ab", ".*c"));
    EXPECT_FALSE(isMatch("aa", "a"));
    EXPECT_TRUE(isMatch("aa", "a*"));
    EXPECT_TRUE(isMatch("aaa", "a*a"));
    EXPECT_TRUE(isMatch("ab", ".*"));
    EXPECT_TRUE(isMatch("aab", "c*a*b"));
    EXPECT_FALSE(isMatch("mississippi", "mis*is*p*."));
}

int main(int argc, char *argv[])
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
