/*
 * ==============================================================
 *
 *       FileName: 0001.cpp
 *    Description:
 *
 *         Author: zhaiyu, zishuzy@gmail.com
 *        Created: 2018-11-24 20:18:43
 *  Last Modified: 2018-12-10 15:55:01
 *
 *  Copyright (C) 2018 zhaiyu. All rights reserved.
 *
 * ==============================================================
 */

#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
#if 0
        // T - O(n^2)
        // S - O(1)
        vector<int> result(2);
        int len = nums.size();
        for (int i = 0; i < len; ++i) {
            for (int j = i + 1; j < len; ++j) {
                if (nums[i] + nums[j] == target) {
                    result[0] = i;
                    result[1] = j;
                }
            }
        }
#endif
        // T - O(n^2)
        // S - O(n)
        unordered_map<int, int> map_num;
        vector<int> result;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            auto p = map_num.find(target - nums[i]);
            if (p != map_num.end()) {
                result.push_back(p->second);
                result.push_back(i);
                break;
            }
            map_num[nums[i]] = i;
        }
        return result;
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

int stringToInteger(string input)
{
    return stoi(input);
}

string integerVectorToString(vector<int> list, int length = -1)
{
    if (length == -1) {
        length = list.size();
    }

    if (length == 0) {
        return "[]";
    }

    string result;
    for (int index = 0; index < length; index++) {
        int number = list[index];
        result += to_string(number) + ", ";
    }
    return "[" + result.substr(0, result.length() - 2) + "]";
}

int main()
{
    string line;
    while (getline(cin, line)) {
        vector<int> nums = stringToIntegerVector(line);
        getline(cin, line);
        int target = stringToInteger(line);

        vector<int> ret = Solution().twoSum(nums, target);

        string out = integerVectorToString(ret);
        cout << out << endl;
    }
    return 0;
}
