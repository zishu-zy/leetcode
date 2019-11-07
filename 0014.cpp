/*
 * ==============================================================
 *
 *       FileName: 0014.cpp
 *    Description:
 *
 *         Author: zhaiyu, zishuzy@gmail.com
 *        Created: 2018-12-30 22:01:50
 *  Last Modified: 2018-12-30 22:19:57
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

string longestCommonPrefix(vector<string> &strs)
{
    if (strs.empty())
        return "";
    if (strs.size() == 1) {
        return strs[0];
    }
    string result = "";
    int slen, rlen = 0;
    int len = min(strs[0].size(), strs[1].size());
    for (int i = 0; i < len; ++i) {
        if (strs[0][i] == strs[1][i]) {
            result.push_back(strs[0][i]);
            ++rlen;
        } else {
            break;
        }
    }
    for (int i = 2; i < (int)strs.size(); ++i) {
        slen = strs[i].size();
        if (slen < rlen) {
            result.erase(result.begin() + slen, result.end());
            rlen = slen;
        }
        for (int j = 0; j < rlen; ++j) {
            if (result[j] != strs[i][j]) {
                result.erase(result.begin() + j, result.end());
                break;
            }
        }
    }
    return result;
}

int main(void)
{
    vector<string> arr;
    arr.push_back("aca");
    arr.push_back("cba");
    std::cout << longestCommonPrefix(arr) << std::endl;

    return 0;
}
