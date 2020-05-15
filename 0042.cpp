
#include "data_define.h"

// 最快的
class Solution
{
public:
    int trap(vector<int> &height)
    {
        if (height.size() == 0) {
            return 0;
        }
        int size = height.size();
        int left = 0;
        int right = size - 1;
        int leftMax = height[0];
        int rightMax = height[size - 1];
        int ans = 0;
        while (left < right) {
            if (height[left] < height[right]) {
                if (height[left] > leftMax) {
                    leftMax = height[left];
                } else {
                    ans += leftMax - height[left];
                }
                ++left;
            } else {
                if (height[right] > rightMax) {
                    rightMax = height[right];
                } else {
                    ans += rightMax - height[right];
                }
                --right;
            }
        }
        return ans;
    }
};

// class Solution
// {
// private:
//     vector<int> vecTmp;

// public:
//     void helper(vector<int> &height, int n_start, int n_end, int n_height)
//     {
//         for (int i = n_start; i <= n_end; ++i) {
//             if (n_height > height.at(i)) {
//                 int nTmp = n_height - height.at(i);
//                 if (nTmp > vecTmp.at(i)) {
//                     vecTmp[i] = nTmp;
//                 }
//             }
//         }
//     }
//     int trap(vector<int> &height)
//     {
//         int nLen = height.size();
//         if (nLen == 0 || nLen == 1) {
//             return 0;
//         }
//         vecTmp.resize(nLen);
//         int nLeftHeight = height.at(0);
//         int nLeftIndex = 0;
//         int nRightHeight = height.at(1);
//         int nRightIndex = 1;
//         int nRet = 0;
//         for (int i = 2; i < nLen; ++i) {
//             if (height.at(i) < nRightHeight) {
//                 helper(height, nLeftIndex + 1, nRightIndex - 1,
//                        min(nLeftHeight, nRightHeight));
//                 if (nRightHeight > nLeftHeight) {
//                     nLeftHeight = nRightHeight;
//                     nLeftIndex = nRightIndex;
//                 }
//             }
//             nRightHeight = height.at(i);
//             nRightIndex = i;
//         }
//         helper(height, nLeftIndex + 1, nRightIndex - 1,
//                min(nLeftHeight, nRightHeight));
//         for (int i = 0; i < nLen; ++i) {
//             nRet += vecTmp.at(i);
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
        vector<int> height = stringToIntegerVector(line);

        int ret = Solution().trap(height);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
