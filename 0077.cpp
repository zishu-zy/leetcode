
#include "data_define.h"
class Solution
{
public:
    void dfs(vector<vector<int>> &vec_ret, vector<int> &vec_tmp, int n_start, int n, int k)
    {
        if (vec_tmp.size() == k) {
            vec_ret.push_back(vec_tmp);
            return;
        }
        // vector<bool> vecFlag(n, false);
        for (int i = n_start; i <= n; i++) {
            // if (vecFlag[i]) {
            //     continue;
            // }
            // vecFlag[i] = true;
            vec_tmp.push_back(i);
            dfs(vec_ret, vec_tmp, i + 1, n, k);
            vec_tmp.pop_back();
            // vecFlag[i] = false;
        }
    }

    vector<vector<int>> combine(int n, int k)
    {
        vector<vector<int>> vecRet;
        vector<int> vecTmp;
        dfs(vecRet, vecTmp, 1, n, k);
        return vecRet;
    }
};

TEST(Solution, leetcode)
{
    vector<int> input;
    vector<vector<int>> output;
    vector<vector<int>> expected;

    input = {4, 2};
    output = Solution().combine(input[0], input[1]);
    expected = {{2, 4}, {3, 4}, {2, 3}, {1, 2}, {1, 3}, {1, 4}};
    EXPECT_TRUE(isEqualWithoutOrder_2(output, expected))
        << "\ninput:   " << getString(input) << "\nouput:   " << getString(output)
        << "\nexpected:" << getString(expected);

    input = {4, 3};
    output = Solution().combine(input[0], input[1]);
    expected = {{1, 2, 3}, {1, 2, 4}, {1, 3, 4}, {2, 3, 4}};
    EXPECT_TRUE(isEqualWithoutOrder_2(output, expected))
        << "\ninput:   " << getString(input) << "\nouput:   " << getString(output)
        << "\nexpected:" << getString(expected);
}

int main(int argc, char *argv[])
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
