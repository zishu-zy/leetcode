/*
 * ==============================================================
 *
 *       FileName: 0006.cpp
 *    Description:
 *
 *         Author: zhaiyu, zishuzy@gmail.com
 *        Created: 2018-12-08 16:58:25
 *  Last Modified: 2018-12-09 10:10:21
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
    string convert(string s, int numRows)
    {
        if (numRows == 1)
            return s;

        vector<string> rows(min(numRows, int(s.size())));
        int curRow = 0;
        bool goingDown = false;

        for (char c : s) {
            rows[curRow] += c;
            if (curRow == 0 || curRow == numRows - 1)
                goingDown = !goingDown;
            curRow += goingDown ? 1 : -1;
        }

        string ret;
        for (string row : rows)
            ret += row;
        return ret;

        // int len = s.size();
        // int cl0 = len / numRows + 1;
        // int cl1 = len % numRows + 1;
        // int cl = cl0 * cl1;
        // vector<vector<char>> arr(numRows, vector<char>(cl, 0));
        // bool status = false;
        // int r = 0, c = 0;
        // for (int i = 0; i < len; ++i) {
        //     arr[r][c] = s[i];
        //     if (r == numRows - 1) {
        //         status = !status;
        //     } else if (r == 0) {
        //         status = !status;
        //     }
        //     if (status) {
        //         r++;
        //     } else {
        //         r--;
        //         c++;
        //     }
        // }
        // string result;
        // for (auto it : arr) {
        //     for (auto i : it) {
        //         if (i != 0) {
        //             result.push_back(i);
        //         }
        //     }
        // }
        // return result;
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

int stringToInteger(string input)
{
    return stoi(input);
}

int main()
{
    string line;
    while (getline(cin, line)) {
        string s = stringToString(line);
        getline(cin, line);
        int numRows = stringToInteger(line);

        string ret = Solution().convert(s, numRows);

        string out = (ret);
        cout << out << endl;
    }
    return 0;
}
