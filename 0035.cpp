
#include "data_define.h"

// 最快的
class Solution
{
public:
    int searchInsert(vector<int> &nums, int target)
    {
        if (nums.size() == 0)
            return 0;
        if (nums[nums.size() - 1] < target)
            return nums.size();

        int left = 0;
        int right = nums.size() - 1;
        int middle;
        while (left < right) {
            middle = (left + right) / 2;
            if (nums[middle] > target)
                right = middle;
            else if (nums[middle] < target)
                left = middle + 1;
            else
                return middle;
        }
        return left;
    }
};

// class Solution
// {
// public:
//     int searchInsert(vector<int> &nums, int target)
//     {
//         if (nums.empty()) {
//             return 0;
//         }
//         int nLeftIndex = 0;
//         int nRightIndex = nums.size() - 1;
//         int nMidIndex = nLeftIndex + (nRightIndex - nLeftIndex) / 2;
//         int nRet = -1;
//         while (nLeftIndex <= nRightIndex) {
//             if (nums.at(nMidIndex) == target) {
//                 break;
//             } else if (nums.at(nMidIndex) < target) {
//                 nLeftIndex = nMidIndex + 1;
//             } else {
//                 nRightIndex = nMidIndex - 1;
//             }
//             nMidIndex = nLeftIndex + (nRightIndex - nLeftIndex) / 2;
//         }
//         if (nMidIndex < 0) {
//             return 0;
//         } else if (nMidIndex >= nums.size()) {
//             return nums.size();
//         }
//         if (nums.at(nMidIndex) == target) {
//             nRet = nMidIndex;
//         } else if (nums.at(nMidIndex) > target) {
//             nRet = nMidIndex;
//         } else {
//             nRet = nMidIndex + 1;
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

int stringToInteger(string input)
{
    return stoi(input);
}

int main()
{
    string line;
    while (getline(cin, line)) {
        vector<int> nums = stringToIntegerVector(line);
        getline(cin, line);
        int target = stringToInteger(line);

        int ret = Solution().searchInsert(nums, target);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
