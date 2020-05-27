
#include "data_define.h"

// 最快的 - 果然还是这个方式
class Solution
{
public:
    int totalNQueens(int n)
    {
        dfs(n, 0, 0, 0, 0);
        return this->res;
    }

    void dfs(int n, int row, int col, int ld, int rd)
    {
        if (row >= n) {
            res++;
            return;
        }

        // 将所有能放置 Q 的位置由 0 变成 1，以便进行后续的位遍历
        int bits = ~(col | ld | rd) & ((1 << n) - 1);
        while (bits > 0) {
            int pick = bits & -bits; // 注: x & -x
            dfs(n, row + 1, col | pick, (ld | pick) << 1, (rd | pick) >> 1);
            bits &= bits - 1; // 注: x & (x - 1)
        }
    }

private:
    int res = 0;
};

// class Solution
// {
// public:
//     int totalNQueens(int n)
//     {
//         vector<vector<string>> vecVecRet;
//         if (n == 0) {
//             return 0;
//         }
//         vector<string> tmp;
//         vector<vector<int>> visited(n, vector<int>(n, 0));
//         n_callCount = 0;
//         backtrack(vecVecRet, tmp, visited, n);
//         std::cout << "callCount: " << n_callCount << std::endl;
//         return vecVecRet.size();
//     }
//     void backtrack(vector<vector<string>> &result, vector<string> &tmp,
//                    vector<vector<int>> &visited, int n)
//     {
//         n_callCount++;
//         int nTmpSize = tmp.size();
//         for (int i = nTmpSize; i < n && i == tmp.size(); ++i) {
//             for (int j = 0; j < n; ++j) {
//                 if (visited[i][j] > 0) {
//                     continue;
//                 }
//                 for (int k = 0; k < n; ++k) {
//                     visited[i][k] += 1;
//                     visited[k][j] += 1;
//                     int i1 = i - k;
//                     int i2 = i + k;
//                     int j1 = j - k;
//                     int j2 = j + k;
//                     if (i1 >= 0 && i1 < n && j1 >= 0 && j1 < n) {
//                         visited[i1][j1] += 1;
//                     }
//                     if (i1 >= 0 && i1 < n && j2 >= 0 && j2 < n) {
//                         visited[i1][j2] += 1;
//                     }
//                     if (i2 >= 0 && i2 < n && j1 >= 0 && j1 < n) {
//                         visited[i2][j1] += 1;
//                     }
//                     if (i2 >= 0 && i2 < n && j2 >= 0 && j2 < n) {
//                         visited[i2][j2] += 1;
//                     }
//                 }
//                 std::string strTmp(n, '.');
//                 strTmp[j] = 'Q';
//                 tmp.push_back(strTmp);
//                 if (i == n - 1) {
//                     result.push_back(tmp);
//                 } else {
//                     backtrack(result, tmp, visited, n);
//                 }
//                 tmp.pop_back();
//                 for (int k = 0; k < n; ++k) {
//                     visited[i][k] -= 1;
//                     visited[k][j] -= 1;
//                     int i1 = i - k;
//                     int i2 = i + k;
//                     int j1 = j - k;
//                     int j2 = j + k;
//                     if (i1 >= 0 && i1 < n && j1 >= 0 && j1 < n) {
//                         visited[i1][j1] -= 1;
//                     }
//                     if (i1 >= 0 && i1 < n && j2 >= 0 && j2 < n) {
//                         visited[i1][j2] -= 1;
//                     }
//                     if (i2 >= 0 && i2 < n && j1 >= 0 && j1 < n) {
//                         visited[i2][j1] -= 1;
//                     }
//                     if (i2 >= 0 && i2 < n && j2 >= 0 && j2 < n) {
//                         visited[i2][j2] -= 1;
//                     }
//                 }
//             }
//         }
//     }

// private:
//     int n_callCount;
// };

TEST(Solution, leetcode)
{
    vector<vector<string>> vecVecActual;
    vector<vector<string>> vecVecExpected;

    EXPECT_EQ(Solution().totalNQueens(8), 92);
    EXPECT_EQ(Solution().totalNQueens(9), 352);
}

int main(int argc, char *argv[])
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
