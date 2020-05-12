
#include "data_define.h"

// 最快的
class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        // vector<int> res(2, -1) 表示初始化数组大小为2，每个值都是-1。
        vector<int> res(2, -1);
        int left = 0, right = nums.size();
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < target)
                left = mid + 1;
            else
                right = mid;
        }
        if (right == nums.size() || nums[right] != target)
            return res;
        res[0] = right;
        right = nums.size();
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] <= target)
                left = mid + 1;
            else
                right = mid;
        }
        res[1] = right - 1;
        return res;
    }
};

// class Solution
// {
// public:
//     int helperLeft(vector<int> &nums, int target, int n_left, int n_right)
//     {
//         int nLeftIndex = n_left;
//         int nRightIndex = n_right;
//         int nMidIndex = n_left + (n_right - n_left) / 2;
//         while (nLeftIndex < nRightIndex) {
//             if (nums.at(nMidIndex) == target) {
//                 nRightIndex = nMidIndex;
//             } else if (nums.at(nMidIndex) < target) {
//                 nLeftIndex = nMidIndex + 1;
//             } else {
//                 nRightIndex = nMidIndex - 1;
//             }
//             nMidIndex = nLeftIndex + (nRightIndex - nLeftIndex) / 2;
//         }
//         if (nums.at(nLeftIndex) == target) {
//             nRightIndex = nLeftIndex;
//         }
//         return nRightIndex;
//     }
//     int helperRight(vector<int> &nums, int target, int n_left, int n_right)
//     {
//         int nLeftIndex = n_left;
//         int nRightIndex = n_right;
//         int nMidIndex = n_left + (n_right - n_left) / 2;
//         while (nLeftIndex < nRightIndex) {
//             if (nums.at(nMidIndex) == target) {
//                 nLeftIndex = nMidIndex;
//             } else if (nums.at(nMidIndex) < target) {
//                 nLeftIndex = nMidIndex + 1;
//             } else {
//                 nRightIndex = nMidIndex - 1;
//             }
//             nMidIndex = nRightIndex - (nRightIndex - nLeftIndex) / 2;
//         }
//         if (nums.at(nRightIndex) == target) {
//             nLeftIndex = nRightIndex;
//         }
//         return nLeftIndex;
//     }
//     vector<int> searchRange(vector<int> &nums, int target)
//     {
//         vector<int> vecRet(2, -1);
//         if (nums.size() == 0) {
//             return vecRet;
//         }
//         int nLeftIndex = 0;
//         int nRightIndex = nums.size() - 1;
//         int nMidIndex = nLeftIndex + (nRightIndex - nLeftIndex) / 2;
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
//         if (nMidIndex >= 0 && nMidIndex < nums.size() &&
//             nums.at(nMidIndex) == target) {
//             vecRet[0] = helperLeft(nums, target, nLeftIndex, nMidIndex);
//             vecRet[1] = helperRight(nums, target, nMidIndex, nRightIndex);
//         }
//         return vecRet;
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

        vector<int> ret = Solution().searchRange(nums, target);

        string out = integerVectorToString(ret);
        cout << out << endl;
    }
    return 0;
}
