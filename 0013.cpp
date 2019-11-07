/*
 * ==============================================================
 *
 *       FileName: 0013.cpp
 *    Description:
 *
 *         Author: zhaiyu, zishuzy@gmail.com
 *        Created: 2018-12-30 16:36:35
 *  Last Modified: 2018-12-30 17:02:10
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

class Solution
{
public:
    int romanToInt(string s)
    {
        int result = 0;
        unordered_map<char, int> ds;
        ds.insert(pair<char, int>('M', 1000));
        ds.insert(pair<char, int>('D', 500));
        ds.insert(pair<char, int>('C', 100));
        ds.insert(pair<char, int>('L', 50));
        ds.insert(pair<char, int>('X', 10));
        ds.insert(pair<char, int>('V', 5));
        ds.insert(pair<char, int>('I', 1));
        int len = s.size();
        result += ds.find(s[0])->second;
        for (int i = 1; i < len; ++i) {
            result += ds.find(s[i])->second;
            if (ds.find(s[i])->second > ds.find(s[i - 1])->second) {
                result -= 2 * ds.find(s[i - 1])->second;
            }
        }
        return result;
    }
};

string stringToString(string input)
{
    assert(input.length() >= 2);
    string result;
    for (int i = 1; i < (int)input.length() - 1; i++) {
        char currentChar = input[i];
        if (input[i] == '\\') {
            char nextChar = input[i + 1];
            switch (nextChar) {
            case '\"':
                result.push_back('\"');
                break;
            case '/':
                result.push_back('/');
                break;
            case '\\':
                result.push_back('\\');
                break;
            case 'b':
                result.push_back('\b');
                break;
            case 'f':
                result.push_back('\f');
                break;
            case 'r':
                result.push_back('\r');
                break;
            case 'n':
                result.push_back('\n');
                break;
            case 't':
                result.push_back('\t');
                break;
            default:
                break;
            }
            i++;
        } else {
            result.push_back(currentChar);
        }
    }
    return result;
}

int main()
{
    string line;
    while (getline(cin, line)) {
        string s = stringToString(line);

        int ret = Solution().romanToInt(s);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
