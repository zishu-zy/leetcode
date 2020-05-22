
#include "data_define.h"

// 最快的
class Solution
{
public:
    void rotate(vector<vector<int>> &matrix)
    {
        int n = matrix.size() - 1;
        int tmp;
        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n - i; ++j) {
                tmp = matrix[i][j];
                matrix[i][j] = matrix[n - j][i];         //上 = 左
                matrix[n - j][i] = matrix[n - i][n - j]; //左 = 下
                matrix[n - i][n - j] = matrix[j][n - i]; //下 = 右
                matrix[j][n - i] = tmp;                  //右 = 原上
            }
        }
    }
};

// class Solution
// {
// public:
//     void helper(int &i, int &j, int n_step, int off)
//     {
//         i -= off;
//         j -= off;
//         int di, dj;
//         if (i == 0) {
//             di = j;
//             dj = n_step;
//         } else if (j == n_step) {
//             di = j;
//             dj = n_step - i;
//         } else if (i == n_step) {
//             di = j;
//             dj = 0;
//         } else {
//             di = 0;
//             dj = n_step - i;
//         }
//         i = di + off;
//         j = dj + off;
//     }
//     void rotate(vector<vector<int>> &matrix)
//     {
//         int nLen = matrix.size();
//         if (nLen == 0 || nLen == 1)
//             return;
//         int nRowCount = (int)ceil(nLen / 2.0);
//         for (int i = 0; i < nRowCount; ++i) {
//             int nAddNum = nLen - i * 2 - 1;
//             for (int j = i; j < nLen - i - 1; ++j) {
//                 // std::cout << i << j << std::endl;
//                 int si = i, sj = j;
//                 int di = j, dj = nLen - i - 1;
//                 // std::cout << si << " " << sj << " -- " << di << " " << dj
//                 //           << std::endl;
//                 int nSwapTmp = matrix[si][sj];
//                 swap(nSwapTmp, matrix[di][dj]);
//                 // si = di;
//                 // sj = dj;
//                 helper(di, dj, nAddNum, i);
//                 // std::cout << si << " " << sj << " -- " << di << " " << dj
//                 //           << std::endl;
//                 swap(nSwapTmp, matrix[di][dj]);
//                 // si = di;
//                 // sj = dj;
//                 helper(di, dj, nAddNum, i);
//                 // std::cout << si << " " << sj << " -- " << di << " " << dj
//                 //           << std::endl;
//                 swap(nSwapTmp, matrix[di][dj]);
//                 // si = di;
//                 // sj = dj;
//                 helper(di, dj, nAddNum, i);
//                 // std::cout << si << " " << sj << " -- " << di << " " << dj
//                 //           << std::endl;
//                 swap(nSwapTmp, matrix[di][dj]);
//             }
//         }
//     }
// };

vector<vector<int>> rotate(vector<vector<int>> &&matrix)
{
    vector<vector<int>> tmp(matrix);
    Solution().rotate(tmp);
    return tmp;
}

TEST(Solution, leetcode)
{
    vector<vector<int>> vecVecActual;
    vector<vector<int>> vecVecExpected;

    vecVecActual = rotate(vector<vector<int>>{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}});
    vecVecExpected = vector<vector<int>>{{7, 4, 1}, {8, 5, 2}, {9, 6, 3}};
    EXPECT_TRUE(vecVecActual == vecVecExpected)
        << "  Actual:\n"
        << getString(vecVecActual) << "\n"
        << "Expected:\n"
        << getString(vecVecExpected);

    vecVecActual = rotate(vector<vector<int>>{
        {5, 1, 9, 11}, {2, 4, 8, 10}, {13, 3, 6, 7}, {15, 14, 12, 16}});
    vecVecExpected = vector<vector<int>>{
        {15, 13, 2, 5}, {14, 3, 4, 1}, {12, 6, 8, 9}, {16, 7, 10, 11}};
    EXPECT_TRUE(vecVecActual == vecVecExpected)
        << "  Actual:\n"
        << getString(vecVecActual) << "\n"
        << "Expected:\n"
        << getString(vecVecExpected);
}

int main(int argc, char *argv[])
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
