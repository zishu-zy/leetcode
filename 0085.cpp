
#include "data_define.h"

class Solution
{
public:
    int maximalRectangle(vector<vector<char>> &matrix)
    {
        if (matrix.empty()) {
            return 0;
        }
        size_t nRow = matrix.size();
        size_t nCol = matrix[0].size();
        std::vector<std::vector<int>> vecRow(nRow, std::vector<int>(nCol, 0));
        std::vector<std::vector<int>> vecCol(nRow, std::vector<int>(nCol, 0));
        std::vector<std::vector<int>> vecBev(nRow, std::vector<int>(nCol, 0));

        vecRow[0][0] = matrix[0][0] == '1' ? 1 : 0;
        vecCol[0][0] = vecRow[0][0];
        vecBev[0][0] = vecRow[0][0];

        int nRowMax = vecRow[0][0];
        int nColMax = vecCol[0][0];
        int nBevMax = vecBev[0][0];

        for (size_t j = 1; j < nCol; j++) {
            if (matrix[0][j] == '1') {
                vecRow[0][j] = vecRow[0][j - 1] + 1;
                nRowMax = max(nRowMax, vecRow[0][j]);
                vecCol[0][j] = 1;
                nColMax = 1;
                vecBev[0][j] = 1;
                nBevMax = 1;
            } else {
                vecRow[0][j] = 0;
                vecCol[0][j] = 0;
                vecBev[0][j] = 0;
            }
        }

        for (size_t i = 1; i < nRow; i++) {
            if (matrix[i][0] == '1') {
                vecRow[i][0] = 1;
                nRowMax = 1;
                vecCol[i][0] = vecCol[i - 1][0] + 1;
                nColMax = max(nColMax, vecCol[i][0]);
                vecBev[i][0] = 1;
                nBevMax = 1;
            } else {
                vecRow[i][0] = 0;
                vecCol[i][0] = 0;
                vecBev[i][0] = 0;
            }
        }

        for (size_t i = 1; i < nRow; i++) {
            for (size_t j = 1; j < nCol; j++) {
                if (matrix[i][j] == '1') {
                    vecRow[i][j] = vecRow[i][j - 1] + 1;
                    nRowMax = max(nRowMax, vecRow[i][j]);

                    vecCol[i][j] = vecCol[i - 1][j] + 1;
                    nColMax = max(nColMax, vecCol[i][j]);

                    if (matrix[i - 1][j] == '1' && matrix[i][j - 1] == '1' &&
                        matrix[i - 1][j - 1] == '1') {
                        vecBev[i][j] =
                            vecBev[i - 1][j] + vecBev[i][j - 1] + vecBev[i - 1][j - 1] + 1;

                        if (vecBev[i - 1][j] > vecBev[i - 1][j - 1]) {
                            vecBev[i][j] -= vecBev[i - 1][j - 1];
                        }

                        if (vecBev[i][j - 1] > vecBev[i - 1][j - 1]) {
                            vecBev[i][j] -= vecBev[i - 1][j - 1];
                        }
                    } else {
                        vecBev[i][j] = 1;
                    }
                    nBevMax = max(nBevMax, vecBev[i][j]);
                } else {
                    vecBev[i][j] = 0;
                }
            }
        }
        printf("start ----------- \n");
        print(vecRow);
        printf("----------- \n");
        print(vecCol);
        printf("----------- \n");
        print(vecBev);
        printf("end ----------- \n");
        int nAreaRet = max(max(nRowMax, nColMax), nBevMax);
        return nAreaRet;
    }
};

TEST(Solution, leetcode)
{
    vector<vector<char>> input;
    int output;
    int expected;

    input = {{'0', '0', '0', '0', '0', '0', '1'},
             {'0', '0', '0', '0', '1', '1', '1'},
             {'1', '1', '1', '1', '1', '1', '1'},
             {'0', '0', '0', '1', '1', '1', '1'}};
    output = Solution().maximalRectangle(input);
    expected = 9;
    EXPECT_TRUE(output == expected)
        << "\ninput:   " << getString(input) << "\nouput:   " << getString(output)
        << "\nexpected:" << getString(expected);

    input = {{'0', '1'}, {'0', '1'}};
    output = Solution().maximalRectangle(input);
    expected = 2;
    EXPECT_TRUE(output == expected)
        << "\ninput:   " << getString(input) << "\nouput:   " << getString(output)
        << "\nexpected:" << getString(expected);

    input = {{'1', '0', '1', '0', '0'},
             {'1', '0', '1', '1', '1'},
             {'1', '1', '1', '1', '1'},
             {'1', '0', '0', '1', '0'}};
    output = Solution().maximalRectangle(input);
    expected = 6;
    EXPECT_TRUE(output == expected)
        << "\ninput:   " << getString(input) << "\nouput:   " << getString(output)
        << "\nexpected:" << getString(expected);

    input = {{'0'}};
    output = Solution().maximalRectangle(input);
    expected = 0;
    EXPECT_TRUE(output == expected)
        << "\ninput:   " << getString(input) << "\nouput:   " << getString(output)
        << "\nexpected:" << getString(expected);

    input = {};
    output = Solution().maximalRectangle(input);
    expected = 0;
    EXPECT_TRUE(output == expected)
        << "\ninput:   " << getString(input) << "\nouput:   " << getString(output)
        << "\nexpected:" << getString(expected);

    input = {{'1'}};
    output = Solution().maximalRectangle(input);
    expected = 1;
    EXPECT_TRUE(output == expected)
        << "\ninput:   " << getString(input) << "\nouput:   " << getString(output)
        << "\nexpected:" << getString(expected);

    input = {{'0'}, {'0'}};
    output = Solution().maximalRectangle(input);
    expected = 0;
    EXPECT_TRUE(output == expected)
        << "\ninput:   " << getString(input) << "\nouput:   " << getString(output)
        << "\nexpected:" << getString(expected);
}

int main(int argc, char *argv[])
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
