
#include "data_define.h"

class Solution
{
public:
    int minPathSum(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = m == 0 ? 0 : grid.at(0).size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        dp[0][0] = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == 0) {
                    dp[i + 1][j + 1] = dp[i + 1][j] + grid[i][j];
                } else if (j == 0) {
                    dp[i + 1][j + 1] = dp[i][j + 1] + +grid[i][j];
                } else {
                    dp[i + 1][j + 1] = min(dp[i][j + 1], dp[i + 1][j]) + grid[i][j];
                }
            }
        }
        return dp[m][n];
    }
};

TEST(Solution, leetcode)
{
    vector<vector<int>> vecVecInput;

    vecVecInput = {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
    EXPECT_EQ(Solution().minPathSum(vecVecInput), 7) << "input: " << getString(vecVecInput);
}

int main(int argc, char *argv[])
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
