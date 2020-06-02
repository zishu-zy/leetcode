
#include "data_define.h"

// 最快的 - 看是最快的，其实不然
class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        vector<vector<int>> res;
        bool bMerge = true;
        while (bMerge) {
            bMerge = false;
            for (auto data : intervals) {
                bool bCheck = false;
                for (auto it = res.begin(); it != res.end(); it++) {
                    if ((data[0] >= (*it)[0] && data[0] <= (*it)[1]) ||
                        (data[1] >= (*it)[0] && data[1] <= (*it)[1])) {
                        (*it)[0] = min(data[0], (*it)[0]);
                        (*it)[1] = max(data[1], (*it)[1]);
                        bMerge = true;
                        bCheck = true;
                        break;
                    } else if ((data[0] <= (*it)[0] && data[1] >= (*it)[1]) ||
                               (data[0] <= (*it)[0] && data[1] >= (*it)[1])) {
                        (*it)[0] = min(data[0], (*it)[0]);
                        (*it)[1] = max(data[1], (*it)[1]);
                        bMerge = true;
                        bCheck = true;
                        break;
                    }
                }
                if (!bCheck) {
                    res.push_back(data);
                    // bMerge = true;
                }
            }
            intervals = res;
            res.clear();
        }
        return intervals;
    }
};

class Solution2
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        if (intervals.empty())
            return {};
        sort(intervals.begin(), intervals.end(),
             [&](vector<int> &a, vector<int> &b) {
                 if (a.at(0) < b.at(0)) {
                     return true;
                 }
                 return false;
             });
        int nLen = intervals.size();
        int nStart = intervals.at(0).at(0);
        int nEnd = intervals.at(0).at(1);
        vector<vector<int>> vecRet;
        for (int i = 1; i < nLen; ++i) {
            if (intervals[i][0] <= nEnd) {
                nEnd = max(intervals[i][1], nEnd);
            } else {
                vector<int> vecTmp{nStart, nEnd};
                vecRet.push_back(vecTmp);
                nStart = intervals[i][0];
                nEnd = intervals[i][1];
            }
        }
        vector<int> vecTmp{nStart, nEnd};
        vecRet.push_back(vecTmp);
        return vecRet;
    }
};

vector<vector<int>> merge(vector<vector<int>> &&intervals)
{
    return Solution().merge(intervals);
}

TEST(Solution, leetcode)
{
    vector<vector<int>> vecVecActual;
    vector<vector<int>> vecVecExpected;

    vecVecActual =
        merge(vector<vector<int>>{{2, 6}, {1, 3}, {15, 18}, {8, 10}});
    vecVecExpected = vector<vector<int>>{{1, 6}, {8, 10}, {15, 18}};
    EXPECT_TRUE(isEqualWithoutOrder(vecVecActual, vecVecExpected))
        << "  Actual:\n"
        << getString(vecVecActual) << "\n"
        << "Expected:\n"
        << getString(vecVecExpected);

    vecVecActual = merge(vector<vector<int>>{{1, 4}, {4, 5}});
    vecVecExpected = vector<vector<int>>{{1, 5}};
    EXPECT_TRUE(isEqualWithoutOrder(vecVecActual, vecVecExpected))
        << "  Actual:\n"
        << getString(vecVecActual) << "\n"
        << "Expected:\n"
        << getString(vecVecExpected);

    vecVecActual = merge(vector<vector<int>>{{1, 4}});
    vecVecExpected = vector<vector<int>>{{1, 4}};
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
