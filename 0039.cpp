

#include "data_define.h"

// 在调用函数之前判断比在里面好
// 最快的
class Solution
{
public:
    vector<vector<int>> res;
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<int> temp;
        sort(candidates.begin(), candidates.end());
        backtrack(candidates, target, temp, 0);
        return res;
    }
    void backtrack(vector<int> &candidates, int target, vector<int> &temp,
                   int start)
    {
        if (target == 0) {
            res.push_back(temp);
            return;
        }
        for (int i = start; i < candidates.size(); i++) {
            if (target >= candidates[i]) {
                temp.push_back(candidates[i]);
                backtrack(candidates, target - candidates[i], temp, i);
                temp.pop_back();
            }
        }
    }
};

// class Solution
// {
// public:
//     void helper(vector<int> &candidates, int n_start, int target,
//                 vector<int> &vec_ret, vector<vector<int>> &vec_vec_ret)
//     {
//         if (target < 0) {
//             return;
//         } else if (target == 0) {
//             vec_vec_ret.push_back(vec_ret);
//             return;
//         }
//         for (int i = n_start; i < (int)candidates.size(); ++i) {
//             vec_ret.push_back(candidates.at(i));
//             helper(candidates, i, target - candidates.at(i), vec_ret,
//                    vec_vec_ret);
//             vec_ret.erase(vec_ret.end() - 1);
//         }
//     }
//     vector<vector<int>> combinationSum(vector<int> &candidates, int target)
//     {
//         if (candidates.empty()) {
//             return vector<vector<int>>();
//         }
//         sort(candidates.begin(), candidates.end());
//         vector<vector<int>> vecVecRet;
//         vector<int> vecRet;
//         helper(candidates, 0, target, vecRet, vecVecRet);
//         return vecVecRet;
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

int main(void)
{
    string line;
    while (getline(cin, line)) {
        vector<int> nums = stringToIntegerVector(line);
        getline(cin, line);
        int target = stringToInteger(line);

        vector<vector<int>> vecRet = Solution().combinationSum(nums, target);
        print(vecRet);
    }

    return 0;
}
