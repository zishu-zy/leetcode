
#include "data_define.h"

// 整体二分
class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int col = matrix.size();
        if (col == 0)
            return false;
        int row = matrix.front().size();
        int left = 0, right = col * row - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            int elem = matrix[mid / row][mid % row]; //定位到了了中间元素
            if (elem == target)
                return true;
            else if (elem < target)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return false;
    }
};

class Solution2
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int nRows = matrix.size();
        int nColumns = matrix.empty() ? 0 : matrix[0].size();
        if (nRows == 0 || nColumns == 0) {
            return false;
        }
        int nLeft = 0;
        int nRight = nRows - 1;
        int nMayBeRow;
        int nMid = 0;
        if (matrix[nLeft][0] > target) {
            return false;
        } else if (matrix[nRight][0] < target) {
            nMayBeRow = nRight;
        } else {
            while (nLeft <= nRight) {
                nMid = (nRight + nLeft) / 2;
                std::cout << nLeft << " " << nMid << " " << nRight << std::endl;
                if (matrix[nMid][0] == target) {
                    return true;
                } else if (matrix[nMid][0] < target) {
                    nLeft = nMid + 1;
                } else {
                    nRight = nMid - 1;
                }
            }
            nMayBeRow = nRight;
        }
        std::cout << "nMayBeRow: " << nMayBeRow << std::endl;
        nLeft = 0;
        nRight = nColumns - 1;
        while (nLeft <= nRight) {
            nMid = (nRight + nLeft) / 2;
            std::cout << nLeft << " " << nMid << " " << nRight << std::endl;
            if (matrix[nMayBeRow][nMid] == target) {
                return true;
            } else if (matrix[nMayBeRow][nMid] < target) {
                nLeft = nMid + 1;
            } else {
                nRight = nMid - 1;
            }
        }
        return false;
    }
};

TEST(Solution, leetcode)
{
    std::vector<std::vector<int>> vecVecInput;
    int nInput;
    bool bOutput;
    bool bExpected;

    vecVecInput = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 50}};
    nInput = 11;
    bExpected = true;
    bOutput = Solution().searchMatrix(vecVecInput, nInput);
    EXPECT_TRUE(bOutput == bExpected)
        << "\ninput:   " << getString(vecVecInput) << ": " << nInput
        << "\nouput:   " << getString(bOutput) << "\nexpected:" << getString(bExpected);

    vecVecInput = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 50}};
    nInput = 3;
    bExpected = true;
    bOutput = Solution().searchMatrix(vecVecInput, nInput);
    EXPECT_TRUE(bOutput == bExpected)
        << "\ninput:   " << getString(vecVecInput) << ": " << nInput
        << "\nouput:   " << getString(bOutput) << "\nexpected:" << getString(bExpected);

    vecVecInput = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 50}};
    nInput = 13;
    bExpected = false;
    bOutput = Solution().searchMatrix(vecVecInput, nInput);
    EXPECT_TRUE(bOutput == bExpected)
        << "\ninput:   " << getString(vecVecInput) << ": " << nInput
        << "\nouput:   " << getString(bOutput) << "\nexpected:" << getString(bExpected);

    vecVecInput = {{1}};
    nInput = 1;
    bExpected = true;
    bOutput = Solution().searchMatrix(vecVecInput, nInput);
    EXPECT_TRUE(bOutput == bExpected)
        << "\ninput:   " << getString(vecVecInput) << ": " << nInput
        << "\nouput:   " << getString(bOutput) << "\nexpected:" << getString(bExpected);
}

int main(int argc, char *argv[])
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
