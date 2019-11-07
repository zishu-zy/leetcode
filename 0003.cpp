/*
 * ==============================================================
 *
 *       FileName: 0003.cpp
 *    Description:
 *
 *         Author: zhaiyu, zishuzy@gmail.com
 *        Created: 2018-11-25 11:04:24
 *  Last Modified: 2018-12-07 20:52:19
 *
 *  Copyright (C) 2018 zhaiyu. All rights reserved.
 *
 * ==============================================================
 */

#include <algorithm>
#include <cassert>
#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        unordered_set<char> tmpSet;
        int len = s.size();
        int result = 0, ss = 0, se = 0;
        while (ss < len && se < len) {
            if (tmpSet.find(s[se]) == tmpSet.end()) {
                tmpSet.insert(s[se++]);
                result = max(result, se - ss);
            } else {
                tmpSet.erase(tmpSet.find(s[ss++]));
            }
        }
        return result;
    }
};

string stringToString(string input)
{
    assert(input.size() >= 2);
    string result;
    for (int i = 1; i < (int)input.size() - 1; i++) {
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

        int ret = Solution().lengthOfLongestSubstring(s);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
