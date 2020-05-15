
#include "data_define.h"

// 最快的 感觉和我自己的没啥区别啊
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        nums.push_back(0);
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] > 0 && nums[i] < nums.size() && nums[i] != i) {
                if (nums[i] != nums[nums[i]]) {
                    swap(nums[i], nums[nums[i]]);
                    i--;
                }
            }
        }
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] != i) {
                return i;
            }
        }
        return max((int)nums.size(), 1);
    }
};

// class Solution
// {
// public:
//     int firstMissingPositive(vector<int> &nums)
//     {
//         int nLen = nums.size();
//         if (nLen == 0) {
//             return 1;
//         } else if (nLen == 1 && nums.at(0) == 1) {
//             return 2;
//         }
//         for (int i = 0; i < nLen;) {
//             if (nums.at(i) >= nLen || nums.at(i) <= 0) {
//                 ++i;
//                 continue;
//             }
//             if (nums[i] != nums[nums[i] - 1]) {
//                 swap(nums[i], nums[nums[i] - 1]);
//             } else {
//                 ++i;
//             }
//         }
//         print(nums);
//         int nRet = nLen + 1;
//         for (int i = 0; i < nLen; ++i) {
//             if (nums.at(i) != i + 1) {
//                 nRet = i + 1;
//                 break;
//             }
//         }
//         return nRet;
//     }
// };

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

int main()
{
    string line;
    while (getline(cin, line)) {
        vector<int> nums = stringToIntegerVector(line);

        int ret = Solution().firstMissingPositive(nums);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
