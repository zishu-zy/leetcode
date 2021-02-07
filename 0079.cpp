
#include "data_define.h"

class Solution
{
public:
    bool dfs(const vector<vector<char>> &board, vector<vector<bool>> &vec_flag, int n_i, int n_j,
             string &word)
    {
        if (word.empty()) {
            return true;
        }
        if (n_i < 0 || n_i == board.size() || n_j < 0 || n_j == board.at(0).size()) {
            return false;
        }
        if (vec_flag[n_i][n_j]) {
            return false;
        }

        bool bRet = false;
        if (board[n_i][n_j] == word[0]) {
            vec_flag[n_i][n_j] = true;
            std::string strWord(word.substr(1));
            bRet = dfs(board, vec_flag, n_i, n_j + 1, strWord);
            if (bRet) {
                return true;
            }
            bRet = dfs(board, vec_flag, n_i, n_j - 1, strWord);
            if (bRet) {
                return true;
            }
            bRet = dfs(board, vec_flag, n_i + 1, n_j, strWord);
            if (bRet) {
                return true;
            }
            bRet = dfs(board, vec_flag, n_i - 1, n_j, strWord);
            if (bRet) {
                return true;
            }
            vec_flag[n_i][n_j] = false;
        }

        return bRet;
    }

    bool exist(vector<vector<char>> &board, string word)
    {
        if (board.empty()) {
            return false;
        }
        if (board.at(0).empty()) {
            return false;
        }
        vector<vector<bool>> vecFlags(board.size(), vector<bool>(board.at(0).size(), false));
        int i = 0;
        int j = 0;
        bool bRet = false;
        while (i < board.size() && j < board.at(0).size()) {
            if (board[i][j] == word[0]) {
                bRet = dfs(board, vecFlags, i, j, word);
                if (bRet) {
                    break;
                }
            }
            ++j;
            if (j == board.at(0).size()) {
                j = 0;
                ++i;
            }
        }
        return bRet;
    }
};

TEST(Solution, leetcode)
{
    vector<vector<char>> input_1;
    string input_2;
    bool output;
    bool expected;

    input_1 = {{'A'}};
    input_2 = "A";
    output = Solution().exist(input_1, input_2);
    expected = true;
    EXPECT_TRUE(output == expected)
        << "\ninput:   " << getString(input_1) << "\n"
        << input_2 << "\nouput:   " << getString(output) << "\nexpected:" << getString(expected);

    input_1 = {{'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};
    input_2 = "SEE";
    output = Solution().exist(input_1, input_2);
    expected = true;
    EXPECT_TRUE(output == expected)
        << "\ninput:   " << getString(input_1) << "\n"
        << input_2 << "\nouput:   " << getString(output) << "\nexpected:" << getString(expected);

    input_1 = {{'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};
    input_2 = "ABCCED";
    output = Solution().exist(input_1, input_2);
    expected = true;
    EXPECT_TRUE(output == expected)
        << "\ninput:   " << getString(input_1) << "\n"
        << input_2 << "\nouput:   " << getString(output) << "\nexpected:" << getString(expected);

    input_1 = {{'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};
    input_2 = "ABCB";
    output = Solution().exist(input_1, input_2);
    expected = false;
    EXPECT_TRUE(output == expected)
        << "\ninput:   " << getString(input_1) << "\n"
        << input_2 << "\nouput:   " << getString(output) << "\nexpected:" << getString(expected);
}

int main(int argc, char *argv[])
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
