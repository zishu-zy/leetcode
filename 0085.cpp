
#include "data_define.h"

class Solution
{
public:
    int maximalRectangle(vector<vector<char>> &matrix)
    {
        int m = matrix.size();
        if (m == 0) {
            return 0;
        }
        int n = matrix[0].size();
        vector<vector<int>> left(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == '1') {
                    left[i][j] = (j == 0 ? 0 : left[i][j - 1]) + 1;
                }
            }
        }

        int ret = 0;
        for (int j = 0; j < n; j++) { // 对于每一列，使用基于柱状图的方法
            vector<int> up(m, 0), down(m, 0);

            stack<int> stk;
            for (int i = 0; i < m; i++) {
                while (!stk.empty() && left[stk.top()][j] >= left[i][j]) {
                    stk.pop();
                }
                up[i] = stk.empty() ? -1 : stk.top();
                stk.push(i);
            }
            stk = stack<int>();
            for (int i = m - 1; i >= 0; i--) {
                while (!stk.empty() && left[stk.top()][j] >= left[i][j]) {
                    stk.pop();
                }
                down[i] = stk.empty() ? m : stk.top();
                stk.push(i);
            }

            for (int i = 0; i < m; i++) {
                int height = down[i] - up[i] - 1;
                int area = height * left[i][j];
                ret = max(ret, area);
            }
        }
        return ret;
    }
};

class Solution_1
{
public:
    int maximalRectangle(vector<vector<char>> &matrix)
    {
        int m = matrix.size();
        if (m == 0) {
            return 0;
        }
        int n = matrix[0].size();
        vector<vector<int>> left(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == '1') {
                    left[i][j] = (j == 0 ? 0 : left[i][j - 1]) + 1;
                }
            }
        }
        print(left);

        int ret = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == '0') {
                    continue;
                }
                int width = left[i][j];
                int area = width;
                for (int k = i - 1; k >= 0; k--) {
                    width = min(width, left[k][j]);
                    area = max(area, (i - k + 1) * width);
                }
                ret = max(ret, area);
            }
        }
        return ret;
    }
};

TEST(Solution, leetcode)
{
    vector<vector<char>> input;
    int output;
    int expected;

    input = {{'0', '1', '1', '0', '0', '0', '1'},
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
