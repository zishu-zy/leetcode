
#include "data_define.h"

// 最快的
class Solution
{
public:
    int column[9][9] = {0};
    int row[9][9] = {0};
    int box[9][9] = {0};

    vector<vector<char>> board;
    bool solve(int i, int j)
    {
        if (i == 9)
            return true;
        int next_i = i, next_j = 0;
        if (j + 1 >= 9) {
            next_i = i + 1;
            next_j = 0;
        } else
            next_j = j + 1;
        if (board[i][j] == '.') {
            // 9 possible answers
            for (int val = 0; val < 9; val++) {
                int box_index = i / 3 * 3 + j / 3;
                if (!row[i][val] && !column[j][val] && !box[box_index][val]) {
                    row[i][val] = 1;
                    column[j][val] = 1;
                    box[box_index][val] = 1;
                    board[i][j] = val + '1';
                    if (solve(next_i, next_j))
                        return true;
                    row[i][val] = 0;
                    column[j][val] = 0;
                    box[box_index][val] = 0;
                    board[i][j] = '.';
                }
            }
        } else
            return solve(next_i, next_j);
        return false;
    }

    void solveSudoku(vector<vector<char>> &b)
    {
        board = b;
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    int index = board[i][j] - '1';
                    int box_index = i / 3 * 3 + j / 3;
                    row[i][index] = 1;
                    column[j][index] = 1;
                    box[box_index][index] = 1;
                }
            }
        }
        solve(0, 0);
        b = board;
    }
};

// 我被标签中指明的回溯误导了
// class Solution
// {
// public:
//     inline int getBlockIndex(int row, int col)
//     {
//         return (row / 3) * 3 + col / 3;
//     }
//     inline char getRefer(const set<char> &set_row, const set<char> &set_col,
//                          const set<char> &set_block, int n_nums = 0)
//     {
//         int nCount = 0;
//         for (char i = '1'; i <= '9'; ++i) {
//             set<char>::iterator it = set_row.find(i);
//             if (it == set_row.end()) {
//                 continue;
//             }
//             it = set_col.find(i);
//             if (it == set_col.end()) {
//                 continue;
//             }
//             it = set_block.find(i);
//             if (it != set_block.end()) {
//                 if (nCount >= n_nums) {
//                     return i;
//                 } else {
//                     ++nCount;
//                 }
//             }
//         }
//         return '.';
//     }

//     void solveSudoku(vector<vector<char>> &board)
//     {
//         set<char> vecRefer{'1', '2', '3', '4', '5', '6', '7', '8', '9'};
//         vector<set<char>> vecRow(9, vecRefer);
//         vector<set<char>> vecColumn(9, vecRefer);
//         vector<set<char>> vecBlock(9, vecRefer);
//         vector<vector<char>> vecBoard(board);

//         std::cout << std::endl;
//         print(vecBoard);
//         std::cout << std::endl;
//         for (int i = 0; i < 9; ++i) {
//             for (int j = 0; j < 9; ++j) {
//                 char chTmp = vecBoard.at(i).at(j);
//                 if (chTmp != '.') {
//                     vecRow[i].erase(chTmp);
//                     vecColumn[j].erase(chTmp);
//                     vecBlock[getBlockIndex(i, j)].erase(chTmp);
//                 }
//             }
//         }

//         bool bOk = false;
//         int nRecallCount = 0;
//         int nRecallNum = 1;
//         vector<vector<int>> vecRecallNum(9, vector<int>(9, 1));

//         while (!bOk) {
//             bOk = true;
//             int i, j;
//             for (i = 0; bOk && i < 9; ++i) {
//                 for (j = 0; bOk && j < 9; ++j) {
//                     char chTmp_1 = vecBoard.at(i).at(j);
//                     char chTmp_2 = board.at(i).at(j);
//                     if (chTmp_1 != '.') {
//                         continue;
//                     }
//                     if (chTmp_2 == '.') {
//                         char chTmp = getRefer(vecRow.at(i), vecColumn.at(j),
//                                               vecBlock.at(getBlockIndex(i,
//                                               j)));
//                         if (chTmp == '.') {
//                             bOk = false;
//                             break;
//                         }
//                         board[i][j] = chTmp;
//                         vecRow[i].erase(chTmp);
//                         vecColumn[j].erase(chTmp);
//                         vecBlock[getBlockIndex(i, j)].erase(chTmp);
//                     }
//                 }
//             }
//             print(board);
//             std::cout << std::endl;
//             if (bOk) {
//                 break;
//             }
//             --i;
//             for (int nCount = 0; i >= 0; --i) {
//                 for (; j >= 0; --j) {
//                     char chTmp_1 = vecBoard.at(i).at(j);
//                     char chTmp_2 = board.at(i).at(j);
//                     if (chTmp_1 == '.' && chTmp_2 != '.') {
//                         nCount++;
//                         board[i][j] = '.';
//                         vecRow[i].insert(chTmp_2);
//                         vecColumn[j].insert(chTmp_2);
//                         vecBlock[getBlockIndex(i, j)].insert(chTmp_2);
//                     }
//                     if (nCount > nRecallCount) {
//                         char chTmp = getRefer(vecRow.at(i), vecColumn.at(j),
//                                               vecBlock.at(getBlockIndex(i,
//                                               j)), vecRecallNum.at(i).at(j));
//                         if (chTmp == '.') {
//                             vecRecallNum[i][j] = 1;
//                             nRecallCount++;
//                         } else {
//                             vecRecallNum[i][j]++;
//                             nRecallCount = 0;
//                             board[i][j] = chTmp;
//                             vecRow[i].erase(chTmp);
//                             vecColumn[j].erase(chTmp);
//                             vecBlock[getBlockIndex(i, j)].erase(chTmp);
//                             i = j = -1;
//                             break;
//                         }
//                     }
//                 }
//                 j = 8;
//             }
//             print(board);
//             std::cout << std::endl;
//         }
//     }
// };

void trimLeftTrailingSpaces(string &input)
{
    input.erase(input.begin(), find_if(input.begin(), input.end(),
                                       [](int ch) { return !isspace(ch); }));
}

void trimRightTrailingSpaces(string &input)
{
    input.erase(find_if(input.rbegin(), input.rend(),
                        [](int ch) { return !isspace(ch); })
                    .base(),
                input.end());
}

vector<vector<char>> stringToVectorVecChar(string input)
{
    vector<vector<char>> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    vector<char> vecTmp;
    for (int i = 0; i < input.size(); ++i) {
        if (input.at(i) == '[') {
            continue;
        } else if (input.at(i) == ']') {
            output.push_back(vecTmp);
            vecTmp.clear();
        } else if (input.at(i) != '\"' && input.at(i) != ',') {
            vecTmp.push_back(input.at(i));
        }
    }
    return output;
}

int main(void)
{
    string line;
    while (getline(cin, line)) {
        vector<vector<char>> board = stringToVectorVecChar(line);
        Solution s;
        s.solveSudoku(board);
    }
    return 0;
}
