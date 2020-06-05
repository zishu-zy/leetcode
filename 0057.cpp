
#include "data_define.h"

class Solution
{
public:
    vector<vector<int>> insert(vector<vector<int>> &intervals,
                               vector<int> &newInterval)
    {
        vector<vector<int>> vecVecRet;
        if (intervals.empty()) {
            vecVecRet.push_back(newInterval);
            return vecVecRet;;
        }
        int nLen = intervals.size();
        int nFlag = 0;
        int nStart = 0;
        int nEnd = 0;
        for (int i = 0; i < nLen; ++i) {
            if (nFlag == 0) {
                if (newInterval[0] <= intervals[i][0]) {
                    nStart = newInterval[0];
                    nFlag = 1;
                } else if (newInterval[0] <= intervals[i][1]) {
                    nStart = intervals[i][0];
                    nFlag = 1;
                }
            }
            if (nFlag == 1) {
                if (newInterval[1] < intervals[i][0]) {
                    nEnd = newInterval[1];
                    i--;
                } else if (newInterval[1] <= intervals[i][1]) {
                    nEnd = intervals[i][1];
                } else {
                    nEnd = newInterval[1];
                    continue;
                }
                vector<int> vecTmp({nStart, nEnd});
                vecVecRet.push_back(vecTmp);
                vecVecRet.insert(vecVecRet.end(), intervals.begin() + i + 1,
                                 intervals.end());
                nFlag = 2;
                break;
            }
            if (nFlag == 0) {
                vecVecRet.push_back(intervals[i]);
            }
        }
        if (nFlag == 1) {
            vector<int> vecTmp({nStart, nEnd});
            vecVecRet.push_back(vecTmp);
        } else if (nFlag == 0) {
            vecVecRet.push_back(newInterval);
        }
        return vecVecRet;
    }
};

vector<vector<int>> insert(vector<vector<int>> &&intervals,
                           vector<int> &&newInterval)
{
    return Solution().insert(intervals, newInterval);
}

TEST(Solution, leetcode)
{
    vector<vector<int>> vecVecActual;
    vector<vector<int>> vecVecExpected;

    vecVecActual = insert(vector<vector<int>>{}, vector<int>({1, 17}));
    vecVecExpected = vector<vector<int>>{{1, 17}};
    EXPECT_TRUE(isEqualWithoutOrder(vecVecActual, vecVecExpected))
        << "  Actual:\n"
        << getString(vecVecActual) << "\n"
        << "Expected:\n"
        << getString(vecVecExpected);

    vecVecActual = insert(vector<vector<int>>{{2, 4}, {6, 9}, {12, 16}},
                          vector<int>({1, 17}));
    vecVecExpected = vector<vector<int>>{{1, 17}};
    EXPECT_TRUE(isEqualWithoutOrder(vecVecActual, vecVecExpected))
        << "  Actual:\n"
        << getString(vecVecActual) << "\n"
        << "Expected:\n"
        << getString(vecVecExpected);

    vecVecActual = insert(vector<vector<int>>{{1, 4}, {6, 9}, {12, 16}},
                          vector<int>({2, 15}));
    vecVecExpected = vector<vector<int>>{{1, 16}};
    EXPECT_TRUE(isEqualWithoutOrder(vecVecActual, vecVecExpected))
        << "  Actual:\n"
        << getString(vecVecActual) << "\n"
        << "Expected:\n"
        << getString(vecVecExpected);

    vecVecActual =
        insert(vector<vector<int>>{{1, 3}, {6, 9}}, vector<int>({4, 5}));
    vecVecExpected = vector<vector<int>>{{1, 3}, {4, 5}, {6, 9}};
    EXPECT_TRUE(isEqualWithoutOrder(vecVecActual, vecVecExpected))
        << "  Actual:\n"
        << getString(vecVecActual) << "\n"
        << "Expected:\n"
        << getString(vecVecExpected);

    vecVecActual =
        insert(vector<vector<int>>{{3, 4}, {6, 9}}, vector<int>({1, 2}));
    vecVecExpected = vector<vector<int>>{{1, 2}, {3, 4}, {6, 9}};
    EXPECT_TRUE(isEqualWithoutOrder(vecVecActual, vecVecExpected))
        << "  Actual:\n"
        << getString(vecVecActual) << "\n"
        << "Expected:\n"
        << getString(vecVecExpected);

    vecVecActual =
        insert(vector<vector<int>>{{3, 4}, {6, 9}}, vector<int>({11, 20}));
    vecVecExpected = vector<vector<int>>{{3, 4}, {6, 9}, {11, 20}};
    EXPECT_TRUE(isEqualWithoutOrder(vecVecActual, vecVecExpected))
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
