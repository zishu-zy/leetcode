
#include "data_define.h"

class Solution
{
public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {
        int m = obstacleGrid.size();
        int n = m == 0 ? 0 : obstacleGrid.at(0).size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        dp[0][0] = 0;
        dp[0][1] = 1;
        dp[1][0] = 1;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (obstacleGrid[i][j] == 0) {
                    if (i == 0) {
                        dp[i + 1][j + 1] = dp[i + 1][j];
                    } else if (j == 0) {
                        dp[i + 1][j + 1] = dp[i][j + 1];
                    } else {
                        dp[i + 1][j + 1] = dp[i][j + 1] + dp[i + 1][j];
                    }
                } else {
                    dp[i + 1][j + 1] = 0;
                }
            }
        }
        return dp[m][n];
    }
};

TEST(Solution, leetcode)
{
    vector<vector<int>> vecVecInput;

    vecVecInput = {{0, 0}, {1, 0}};
    EXPECT_EQ(Solution().uniquePathsWithObstacles(vecVecInput), 1)
        << "input: " << getString(vecVecInput);
    vecVecInput = {{0, 1, 0}};
    EXPECT_EQ(Solution().uniquePathsWithObstacles(vecVecInput), 0)
        << "input: " << getString(vecVecInput);
    vecVecInput = {{1, 0}};
    EXPECT_EQ(Solution().uniquePathsWithObstacles(vecVecInput), 0)
        << "input: " << getString(vecVecInput);
    vecVecInput = {{0, 0, 0}, {0, 0, 0}, {0, 0, 1}};
    EXPECT_EQ(Solution().uniquePathsWithObstacles(vecVecInput), 0)
        << "input: " << getString(vecVecInput);
    vecVecInput = {{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};
    EXPECT_EQ(Solution().uniquePathsWithObstacles(vecVecInput), 2)
        << "input: " << getString(vecVecInput);
}

int main(int argc, char *argv[])
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
