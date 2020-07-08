
#include "data_define.h"

class Solution
{
public:
    int uniquePaths(int m, int n)
    {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        dp[0][0] = 0;
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (i == 1 || j == 1) {
                    dp[i][j] = 1;
                } else {
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                }
            }
        }
        return dp[m][n];
    }
};

TEST(Solution, leetcode)
{
    EXPECT_EQ(Solution().uniquePaths(3, 2), 3);
    EXPECT_EQ(Solution().uniquePaths(3, 3), 6);
    EXPECT_EQ(Solution().uniquePaths(7, 3), 28);
}

int main(int argc, char *argv[])
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
