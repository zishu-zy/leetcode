/*
 * ==============================================================
 *
 *       FileName: 0169.cpp
 *    Description:
 *
 *         Author: zhaiyu, zishuzy@gmail.com
 *        Created: 2018-11-25 11:37:35
 *  Last Modified: 2018-11-25 11:49:03
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
    int majorityElement(vector<int> &nums)
    {
        int len = nums.size();
        int count = 1;
        int tmp = nums[0];
        for (int i = 1; i < len; ++i) {
            if (nums[i] == tmp) {
                ++count;
            } else {
                --count;
                if (count == 0) {
                    tmp = nums[i];
                    count = 1;
                }
            }
        }
        return tmp;
    }
};

void trimLeftTrailingSpaces(string &input)
{
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) { return !isspace(ch); }));
}

void trimRightTrailingSpaces(string &input)
{
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) { return !isspace(ch); }).base(), input.end());
}

vector<int> stringToIntegerVector(string input)
{
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(stoi(item));
    }
    return output;
}

int main()
{
    string line;
    while (getline(cin, line)) {
        vector<int> nums = stringToIntegerVector(line);

        int ret = Solution().majorityElement(nums);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
