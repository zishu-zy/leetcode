
#include "data_define.h"

class Solution
{
public:
    int minDistance(string word1, string word2)
    {
        if (word1.empty() || word2.empty()) {
            return max(word1.size(), word2.size());
        }
        int nLen1 = word1.size();
        int nLen2 = word2.size();
        vector<vector<int>> dp(nLen1 + 1, vector<int>(nLen2 + 1, 0));
        // for (int i = 0; i < nLen1; i++) {
        //     dp[i + 1][0] = i + 1;
        // }
        // for (int j = 0; j < nLen2; j++) {
        //     dp[0][j + 1] = j + 1;
        // }
        for (int i = 0; i < nLen1; ++i) {
            dp[i + 1][0] = i + 1;
            for (int j = 0; j < nLen2; ++j) {
                dp[0][j + 1] = j + 1;
                if (word1[i] == word2[j]) {
                    dp[i + 1][j + 1] = dp[i][j];
                } else {
                    dp[i + 1][j + 1] = min(dp[i][j], min(dp[i][j + 1], dp[i + 1][j])) + 1;
                }
            }
        }
        // print(dp);
        return dp[nLen1][nLen2];
    }
};

TEST(Solution, leetcode)
{
    std::vector<std::string> vecStrInput;
    int nOutput;
    int nExpected;

    vecStrInput = {"pneumonoultramicroscopicsilicovolcanoconiosis", "ultramicroscopically"};
    nOutput = Solution().minDistance(vecStrInput[0], vecStrInput[1]);
    nExpected = 27;
    EXPECT_TRUE(nOutput == nExpected) << "\ninput:   " << getString(vecStrInput)
                                      << "\nouput:   " << nOutput << "\nexpected:" << nExpected;

    vecStrInput = {"mart", "karma"};
    nOutput = Solution().minDistance(vecStrInput[0], vecStrInput[1]);
    nExpected = 3;
    EXPECT_TRUE(nOutput == nExpected) << "\ninput:   " << getString(vecStrInput)
                                      << "\nouput:   " << nOutput << "\nexpected:" << nExpected;

    vecStrInput = {"bdcdc", "abcd"};
    nOutput = Solution().minDistance(vecStrInput[0], vecStrInput[1]);
    nExpected = 3;
    EXPECT_TRUE(nOutput == nExpected) << "\ninput:   " << getString(vecStrInput)
                                      << "\nouput:   " << nOutput << "\nexpected:" << nExpected;

    vecStrInput = {"horse", "ros"};
    nOutput = Solution().minDistance(vecStrInput[0], vecStrInput[1]);
    nExpected = 3;
    EXPECT_TRUE(nOutput == nExpected) << "\ninput:   " << getString(vecStrInput)
                                      << "\nouput:   " << nOutput << "\nexpected:" << nExpected;

    vecStrInput = {"intention", "execution"};
    nOutput = Solution().minDistance(vecStrInput[0], vecStrInput[1]);
    nExpected = 5;
    EXPECT_TRUE(nOutput == nExpected) << "\ninput:   " << getString(vecStrInput)
                                      << "\nouput:   " << nOutput << "\nexpected:" << nExpected;
}

int main(int argc, char *argv[])
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
