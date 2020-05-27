
#include "data_define.h"

// 最快的 - 没看懂，数学很重要
class Solution
{
public:
    vector<vector<string>> solveNQueens(int n)
    {
        vector<vector<string>> res;
        vector<string> board(n, string(n, '.')); // Make an empty chess board
        n_callCount = 0;
        putQueen(res, board, 0, 0, 0, n, 0);
        std::cout << "call: " << n_callCount << std::endl;
        return res;
    }

    void putQueen(vector<vector<string>> &res, vector<string> &board,
                  long col_v, long left_v, long right_v, const int &n, int row)
    {
        // Terminal case: exceeding the last row
        n_callCount++;
        if (row == n) {
            res.push_back(board);
            return;
        }

        // Backtracking procedure
        // Vacant places are denoted as 1 in the bit number
        long places = (~(col_v | left_v | right_v) & ((1 << n) - 1));
        while (places) { // No places -> no 1's in the bit number -> == 0
            // Take 1 from the lowest bit and make a bit mask 0...010...0
            long pick = (places & -places);
            places = (places & (places - 1));
            // Put a queen and use current pick to update three bit masks of
            // occupied columns
            int col = log(pick) / log(2);
            board[row][col] = 'Q';
            putQueen(res, board, col_v | pick, (pick | left_v) >> 1,
                     (pick | right_v) << 1, n, row + 1);
            board[row][col] = '.';
        }
    }

private:
    int n_callCount;
};

/*
class Solution
{
public:
    vector<vector<string>> solveNQueens(int n)
    {
        vector<vector<string>> vecVecRet;
        if (n == 0) {
            return vecVecRet;
        }
        vector<string> tmp;
        vector<vector<int>> visited(n, vector<int>(n, 0));
        n_callCount = 0;
        backtrack(vecVecRet, tmp, visited, n);
        std::cout << "callCount: " << n_callCount << std::endl;
        return vecVecRet;
    }
    void backtrack(vector<vector<string>> &result, vector<string> &tmp,
                   vector<vector<int>> &visited, int n)
    {
        n_callCount++;
        int nTmpSize = tmp.size();
        for (int i = nTmpSize; i < n && i == tmp.size(); ++i) {
            for (int j = 0; j < n; ++j) {
                if (visited[i][j] > 0) {
                    continue;
                }
                for (int k = 0; k < n; ++k) {
                    visited[i][k] += 1;
                    visited[k][j] += 1;
                    int i1 = i - k;
                    int i2 = i + k;
                    int j1 = j - k;
                    int j2 = j + k;
                    if (i1 >= 0 && i1 < n && j1 >= 0 && j1 < n) {
                        visited[i1][j1] += 1;
                    }
                    if (i1 >= 0 && i1 < n && j2 >= 0 && j2 < n) {
                        visited[i1][j2] += 1;
                    }
                    if (i2 >= 0 && i2 < n && j1 >= 0 && j1 < n) {
                        visited[i2][j1] += 1;
                    }
                    if (i2 >= 0 && i2 < n && j2 >= 0 && j2 < n) {
                        visited[i2][j2] += 1;
                    }
                }
                std::string strTmp(n, '.');
                strTmp[j] = 'Q';
                tmp.push_back(strTmp);
                if (i == n - 1) {
                    result.push_back(tmp);
                } else {
                    backtrack(result, tmp, visited, n);
                }
                tmp.pop_back();
                for (int k = 0; k < n; ++k) {
                    visited[i][k] -= 1;
                    visited[k][j] -= 1;
                    int i1 = i - k;
                    int i2 = i + k;
                    int j1 = j - k;
                    int j2 = j + k;
                    if (i1 >= 0 && i1 < n && j1 >= 0 && j1 < n) {
                        visited[i1][j1] -= 1;
                    }
                    if (i1 >= 0 && i1 < n && j2 >= 0 && j2 < n) {
                        visited[i1][j2] -= 1;
                    }
                    if (i2 >= 0 && i2 < n && j1 >= 0 && j1 < n) {
                        visited[i2][j1] -= 1;
                    }
                    if (i2 >= 0 && i2 < n && j2 >= 0 && j2 < n) {
                        visited[i2][j2] -= 1;
                    }
                }
            }
        }
    }

private:
    int n_callCount;
};
*/

TEST(Solution, leetcode)
{
    vector<vector<string>> vecVecActual;
    vector<vector<string>> vecVecExpected;

    vecVecActual = Solution().solveNQueens(4);
    vecVecExpected = vector<vector<string>>{{".Q..", "...Q", "Q...", "..Q."},
                                            {"..Q.", "Q...", "...Q", ".Q.."}};
    EXPECT_TRUE(isEqualWithoutOrder(vecVecActual, vecVecExpected))
        << "  Actual:\n"
        << getString(vecVecActual) << "\n"
        << "Expected:\n"
        << getString(vecVecExpected);

    vecVecActual = Solution().solveNQueens(8);
    EXPECT_EQ(vecVecActual.size(), 92);

    vecVecActual = Solution().solveNQueens(9);
    EXPECT_EQ(vecVecActual.size(), 352);
}

int main(int argc, char *argv[])
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
