
#include "data_define.h"

// 其中重点是给第一行和第一列标识为0
class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        bool flag = false;
        for (int i = 0; i < matrix.size(); i++) {
            if (matrix[i][0] == 0) {
                flag = true;
                break;
            }
        }
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 1; j < matrix[0].size(); j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        for (int i = 1; i < matrix[0].size(); i++) {
            if (matrix[0][i] == 0) {
                for (int j = 1; j < matrix.size(); j++) {
                    matrix[j][i] = 0;
                }
            }
        }
        for (int i = 1; i < matrix.size(); i++) {
            if (matrix[i][0] == 0) {
                for (int j = 0; j < matrix[0].size(); j++) {
                    matrix[i][j] = 0;
                }
            }
        }
        if (!matrix[0][0]) {
            for (int i = 0; i < matrix[0].size(); i++)
                matrix[0][i] = 0;
        }
        if (flag) {
            for (int i = 0; i < matrix.size(); i++)
                matrix[i][0] = 0;
        }
    }
};

class Solution2
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        std::set<int> setRows;
        std::set<int> setColumns;
        int nRows = matrix.size();
        int nColumns = matrix.empty() ? 0 : matrix[0].size();
        for (int i = 0; i < nRows; ++i) {
            for (int j = 0; j < nColumns; ++j) {
                if (matrix[i][j] == 0) {
                    setRows.insert(i);
                    setColumns.insert(j);
                }
            }
        }
        for (auto i : setRows) {
            std::cout << "row:" << i << std::endl;
            for (int j = 0; j < nColumns; ++j) {
                matrix[i][j] = 0;
            }
        }
        for (auto j : setColumns) {
            std::cout << "column:" << j << std::endl;
            for (int i = 0; i < nRows; ++i) {
                matrix[i][j] = 0;
            }
        }
        std::cout << "end" << std::endl;
    }
};

TEST(Solution, leetcode)
{
    std::vector<std::vector<int>> vecVecInput;
    std::vector<std::vector<int>> vecVecOutput;
    std::vector<std::vector<int>> vecVecExpected;

    vecVecInput = {{0, 1, 2, 0}, {3, 4, 5, 2}, {1, 3, 1, 5}, {0, 2, 3, 0}};
    vecVecExpected = {{0, 0, 0, 0}, {0, 4, 5, 0}, {0, 3, 1, 0}, {0, 2, 3, 0}};
    vecVecOutput = vecVecInput;
    Solution().setZeroes(vecVecOutput);
    EXPECT_TRUE(vecVecOutput == vecVecOutput)
        << "\ninput:   " << getString(vecVecInput) << "\nouput:   " << getString(vecVecOutput)
        << "\nexpected:" << getString(vecVecExpected);

    vecVecInput = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
    vecVecExpected = {{1, 0, 1}, {0, 0, 0}, {1, 0, 1}};
    vecVecOutput = vecVecInput;
    Solution().setZeroes(vecVecOutput);
    EXPECT_TRUE(vecVecOutput == vecVecOutput)
        << "\ninput:   " << getString(vecVecInput) << "\nouput:   " << getString(vecVecOutput)
        << "\nexpected:" << getString(vecVecExpected);

    vecVecInput = {{0, 1, 2, 0}, {3, 4, 5, 2}, {1, 3, 15}};
    vecVecExpected = {{0, 0, 0, 0}, {0, 4, 5, 0}, {0, 3, 1, 0}};
    vecVecOutput = vecVecInput;
    Solution().setZeroes(vecVecOutput);
    EXPECT_TRUE(vecVecOutput == vecVecOutput)
        << "\ninput:   " << getString(vecVecInput) << "\nouput:   " << getString(vecVecOutput)
        << "\nexpected:" << getString(vecVecExpected);
}

int main(int argc, char *argv[])
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
