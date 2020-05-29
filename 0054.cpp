
#include "data_define.h"

class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        if (matrix.empty()) {
            return {};
        }
        int m = matrix.size();
        int n = matrix.at(0).size();
        vector<vector<int>> visited(m, vector<int>(n, 0));
        vector<int> vecRet;
        int i = 0;
        int j = 0;
        int nFlag = 0;
        int nNumCount = n * m;
        while (vecRet.size() < nNumCount) {
            if (visited.at(i).at(j) != 1) {
                vecRet.push_back(matrix.at(i).at(j));
                visited[i][j] = 1;
            }
            switch (nFlag) {
            case 0:
                ++j;
                if (j >= n) {
                    nFlag = 1;
                    j = n - 1;
                } else if (visited.at(i).at(j) == 1) {
                    nFlag = 1;
                    --j;
                    ++i;
                }
                break;
            case 1:
                ++i;
                if (i >= m) {
                    nFlag = 2;
                    i = m - 1;
                } else if (visited.at(i).at(j) == 1) {
                    nFlag = 2;
                    --i;
                    --j;
                }
                break;
            case 2:
                --j;
                if (j < 0) {
                    nFlag = 3;
                    j = 0;
                } else if (visited.at(i).at(j) == 1) {
                    nFlag = 3;
                    ++j;
                    --i;
                }
                break;
            case 3:
                --i;
                if (i < 0) {
                    nFlag = 0;
                    i = 0;
                } else if (visited.at(i).at(j) == 1) {
                    nFlag = 0;
                    ++i;
                    ++j;
                }
                break;
            default:
                break;
            }
        }
        return vecRet;
    }
};

vector<int> spiralOrder(vector<vector<int>> &&matrix)
{
    return Solution().spiralOrder(matrix);
}

vector<int> spiralOrder(vector<vector<int>> &matrix)
{
    return Solution().spiralOrder(matrix);
}

TEST(Solution, leetcode)
{
    vector<int> vecVecActual;
    vector<int> vecVecExpected;

    vecVecActual = spiralOrder({{1, 2, 3}, {4, 5, 6}, {7, 8, 9}});
    vecVecExpected = vector<int>({1, 2, 3, 6, 9, 8, 7, 4, 5});
    EXPECT_TRUE(vecVecActual == vecVecExpected)
        << "  Actual:\n"
        << getString(vecVecActual) << "\n"
        << "Expected:\n"
        << getString(vecVecExpected);

    vecVecActual = spiralOrder({{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}});
    vecVecExpected = vector<int>({1, 2, 3, 4, 8, 12, 11, 10, 9, 5, 6, 7});
    EXPECT_TRUE(vecVecActual == vecVecExpected)
        << "  Actual:\n"
        << getString(vecVecActual) << "\n"
        << "Expected:\n"
        << getString(vecVecExpected);

    vector<vector<int>> vecVecTemp;
    for (int i = 0; i < 5; ++i) {
        vector<int> vecTmp;
        for (int j = 0; j < 5; ++j) {
            vecTmp.push_back(i * 5 + j + 1);
        }
        vecVecTemp.push_back(vecTmp);
    }
    vecVecActual = spiralOrder(vecVecTemp);
    vecVecExpected =
        vector<int>({1,  2,  3, 4, 5, 10, 15, 20, 25, 24, 23, 22, 21,
                     16, 11, 6, 7, 8, 9,  14, 19, 18, 17, 12, 13});
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
