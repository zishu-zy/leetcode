
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
            if (m_nLastVal == vec_input[i]) {
                continue;
            }
            vec_tmp.push_back(vec_input[i]);
            dfs(vec_ret, vec_tmp, vec_input, i + 1, n_len);
            vec_tmp.pop_back();
            m_nLastVal = vec_input[i];
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        m_nLastVal = 0;
        sort(nums.begin(), nums.end());
        vector<vector<int>> vecVecRet;
        vector<int> vecTmp;
        for (size_t i = 0; i <= nums.size(); i++) {
            m_nLastVal = -11;
            dfs(vecVecRet, vecTmp, nums, 0, i);
        }
        return vecVecRet;
    }

private:
    int m_nLastVal;
};

TEST(Solution, leetcode)
{
    vector<int> input;
    vector<vector<int>> output;
    vector<vector<int>> expected;

    input = {1, 2, 2, 2, 2, 3};
    output = Solution().subsetsWithDup(input);
    expected = {{}, {1}, {1, 2}, {1, 2, 2}, {2}, {2, 2}};
    EXPECT_TRUE(isEqualWithoutOrder_2(output, expected))
        << "\ninput:   " << getString(input) << "\nouput:   " << getString(output)
        << "\nexpected:" << getString(expected);

    input = {2, 1, 2, 1, 3};
    output = Solution().subsetsWithDup(input);
    expected = {{},           {1},       {1, 1}, {1, 1, 2}, {1, 1, 2, 2}, {1, 1, 2, 2, 3},
                {1, 1, 2, 3}, {1, 1, 3}, {1, 2}, {1, 2, 2}, {1, 2, 2, 3}, {1, 2, 3},
                {1, 3},       {2},       {2, 2}, {2, 2, 3}, {2, 3},       {3}};

    EXPECT_TRUE(isEqualWithoutOrder_2(output, expected))
        << "\ninput:   " << getString(input) << "\nouput:   " << getString(output)
        << "\nexpected:" << getString(expected);

    input = {1, 2, 2};
    output = Solution().subsetsWithDup(input);
    expected = {{}, {1}, {1, 2}, {1, 2, 2}, {2}, {2, 2}};
    EXPECT_TRUE(isEqualWithoutOrder_2(output, expected))
        << "\ninput:   " << getString(input) << "\nouput:   " << getString(output)
        << "\nexpected:" << getString(expected);
}

int main(int argc, char *argv[])
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
