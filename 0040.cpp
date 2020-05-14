
#include "data_define.h"

class Solution
{
public:
    void helper(vector<int> &candidates, int n_start, int target,
                vector<int> &vec_ret, vector<vector<int>> &vec_vec_ret)
    {
        if (target == 0) {
            vec_vec_ret.push_back(vec_ret);
            return;
        }
        int nLastValue = 0;
        for (int i = n_start; i < (int)candidates.size(); ++i) {
            if (candidates.at(i) > target) {
                break;
            } else if (nLastValue == candidates.at(i)) {
                continue;
            }
            vec_ret.push_back(candidates.at(i));
            helper(candidates, i + 1, target - candidates.at(i), vec_ret,
                   vec_vec_ret);
            nLastValue = vec_ret.back();
            vec_ret.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        if (candidates.empty()) {
            return vector<vector<int>>();
        }
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> vecVecRet;
        vector<int> vecRet;
        helper(candidates, 0, target, vecRet, vecVecRet);
        return vecVecRet;
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

int main(void)
{
    string line;
    while (getline(cin, line)) {
        vector<int> nums = stringToIntegerVector(line);
        getline(cin, line);
        int target = stringToInteger(line);

        vector<vector<int>> vecRet = Solution().combinationSum2(nums, target);
        print(vecRet);
    }

    return 0;
}
