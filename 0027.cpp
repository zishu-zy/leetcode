#include <algorithm>
#include <assert.h>
#include <fstream>
#include <iostream>
#include <limits.h>
#include <math.h>
#include <sstream>
#include <stack>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution
{
public:
    // 我还是太年轻了，太老实了
    int removeElement(vector<int> &nums, int val)
    {
        int len = nums.size();
        if (len== 0)
            return 0;
        int count = 0;
        for (int i = 0; i < len; i++) {
            if (val != nums[i]) {
                nums[count] = nums[i]; //与删除重复数组元素如出一辙
                count++;
            }
        }
        return count;

        // int len = nums.size();
        // sort(nums.begin(), nums.end());
        // int l = 0;
        // int r = len - 1;
        // int mid;
        // bool flag = false;
        // while (l <= r) {
        //     mid = (l + r) / 2;
        //     if (nums[mid] > val) {
        //         r = mid - 1;
        //     } else if (nums[mid] < val) {
        //         l = mid + 1;
        //     } else {
        //         flag = true;
        //         break;
        //     }
        // }
        // if (flag) {
        //     l = mid;
        //     r = mid;
        //     while (true) {
        //         if (nums[l] != val) {
        //             ++l;
        //             break;
        //         } else {
        //             if (l == 0) {
        //                 break;
        //             }
        //             --l;
        //         }
        //     }
        //     while (true) {
        //         if (nums[r] != val) {
        //             --r;
        //             break;
        //         } else {
        //             if (r == len - 1) {
        //                 break;
        //             }
        //             ++r;
        //         }
        //     }
        //     nums.erase(nums.begin() + l, nums.begin() + r + 1);
        // } else {
        //     return len;
        // }
        // return len - (r - l + 1);
    }
};

void trimLeftTrailingSpaces(string &input)
{
    input.erase(input.begin(), find_if(input.begin(), input.end(),
                                       [](int ch) { return !isspace(ch); }));
}

void trimRightTrailingSpaces(string &input)
{
    input.erase(find_if(input.rbegin(), input.rend(),
                        [](int ch) { return !isspace(ch); })
                    .base(),
                input.end());
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
        int val = stringToInteger(line);

        int ret = Solution().removeElement(nums, val);

        string out = integerVectorToString(nums, ret);
        cout << out << endl;
    }
    return 0;
}
