/*
 * ==============================================================
 *
 *       FileName: 0009.cpp
 *    Description:
 *
 *         Author: zhaiyu, zishuzy@gmail.com
 *        Created: 2018-12-10 11:43:34
 *  Last Modified: 2018-12-10 11:54:01
 *
 *  Copyright (C) 2018 zhaiyu. All rights reserved.
 *
 * ==============================================================
 */

#include <algorithm>
#include <cassert>
#include <iostream>
#include <limits.h>
#include <sstream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution
{
public:
    bool isPalindrome(int x)
    {
        if (x < 0) {
            return false;
        }
        // 用数组时间更快
        string xStr = to_string(x);
        int s = 0, e = xStr.size() - 1;
        while (s < e) {
            if (xStr[s++] != xStr[e--]) {
                return false;
            }
        }
        return true;
    }
};

int stringToInteger(string input)
{
    return stoi(input);
}

string boolToString(bool input)
{
    return input ? "True" : "False";
}

int main()
{
    string line;
    while (getline(cin, line)) {
        int x = stringToInteger(line);

        bool ret = Solution().isPalindrome(x);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}
