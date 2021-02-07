
#include "data_define.h"

class Solution
{
public:
    void dfs(vector<vector<int>> &vec_ret, vector<int> &vec_tmp, const vector<int> &vec_input,
             int n_start, int n_len)
    {
        if (vec_tmp.size() == n_len) {
            vec_ret.push_back(vec_tmp);
            return;
        }
        for (size_t i = n_start; i < vec_input.size(); i++) {
            vec_tmp.push_back(vec_input[i]);
            dfs(vec_ret, vec_tmp, vec_input, i + 1, n_len);
            vec_tmp.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<vector<int>> vecRet;
        vector<int> vecTmp;
        vector<bool> vecFlags(nums.size(), false);
        vecRet.push_back({});
        for (size_t i = 1; i <= nums.size(); i++) {
            dfs(vecRet, vecTmp, nums, 0, i);
        }
        return vecRet;
    }
};

TEST(Solution, leetcode)
{
    vector<int> input;
    vector<vector<int>> output;
    vector<vector<int>> expected;

    input = {1, 2, 3};
    output = Solution().subsets(input);
    expected = {{}, {1}, {2}, {1, 2}, {3}, {1, 3}, {2, 3}, {1, 2, 3}};
    EXPECT_TRUE(isEqualWithoutOrder_2(output, expected))
        << "\ninput:   " << getString(input) << "\nouput:   " << getString(output)
        << "\nexpected:" << getString(expected);

    input = {0};
    output = Solution().subsets(input);
    expected = {{}, {0}};
    EXPECT_TRUE(isEqualWithoutOrder_2(output, expected))
        << "\ninput:   " << getString(input) << "\nouput:   " << getString(output)
        << "\nexpected:" << getString(expected);

    input = {1, 2, 3, 4};
    output = Solution().subsets(input);
    expected = {{}, {1}, {2}, {1, 2}, {3}, {1, 3}, {2, 3}, {1, 2, 3}};
    EXPECT_TRUE(isEqualWithoutOrder_2(output, expected))
        << "\ninput:   " << getString(input) << "\nouput:   " << getString(output)
        << "\nexpected:" << getString(expected);
}

int main(int argc, char *argv[])
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
