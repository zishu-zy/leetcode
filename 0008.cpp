/*
 * ==============================================================
 *
 *       FileName: 0008.cpp
 *    Description:
 *
 *         Author: zhaiyu, zishuzy@gmail.com
 *        Created: 2018-12-09 10:09:17
 *  Last Modified: 2018-12-09 10:39:53
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
    int myAtoi(string str)
    {
        // std::cout << INT_MAX << std::endl;
        // std::cout << INT_MIN << std::endl;
        long long result = 0;
        int len = str.size();
        bool flag = true, start_flag = false;
        for (int i = 0; i < len; ++i) {
            if (!start_flag) {
                if (str[i] == '-') {
                    flag = false;
                    start_flag = true;
                } else if (str[i] == '+') {
                    start_flag = true;
                } else if (str[i] >= '0' && str[i] <= '9') {
                    start_flag = true;
                    result = str[i] - '0';
                } else if (str[i] != ' ') {
                    break;
                }
            } else {
                if (str[i] >= '0' && str[i] <= '9') {
                    result *= 10;
                    result += (str[i] - '0');
                    std::cout << result << std::endl;
                    if ((result - 1) > INT_MAX) {
                        break;
                    }
                } else {
                    break;
                }
            }
        }
        if (!flag) {
            result = -result;
        }
        if (result > INT_MAX) {
            result = INT_MAX;
        } else if (result < INT_MIN) {
            result = INT_MIN;
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
        string str = stringToString(line);

        int ret = Solution().myAtoi(str);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
