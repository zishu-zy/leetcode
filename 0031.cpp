

#include "data_define.h"

// 最快的
class Solution
{
public:
    void nextPermutation(vector<int> &nums)
    {
        int len = nums.size(), index = len - 2, index2 = len - 1;
        while (index >= 0 && nums[index + 1] <= nums[index--]);
        index++;
        while (index2 >= 0 && nums[index] >= nums[index2--]);
        index2++;
        if (index != index2) {
            swap(nums[index], nums[index2]);
            reverse(nums.begin() + index + 1, nums.end());
        } else
            reverse(nums.begin(), nums.end());
    }
};

// class Solution
// {
// public:
//     void nextPermutation(vector<int> &nums)
//     {
//         int nLen = nums.size();
//         int nLeft = nLen - 2;
//         while (nLeft >= 0 && nums[nLeft] >= nums[nLeft + 1]) {
//             --nLeft;
//         }
//         if (nLeft >= 0) {
//             int nRight = nLen - 1;
//             while (nRight >= 0 && nums[nRight] <= nums[nLeft]) {
//                 --nRight;
//             }
//             swap(nums[nLeft], nums[nRight]);
//         }
//         reverse(nums.begin() + nLeft + 1, nums.end());
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

        Solution().nextPermutation(nums);

        string out = integerVectorToString(nums);
        cout << out << endl;
    }
    return 0;
}
