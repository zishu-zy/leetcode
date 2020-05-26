
#include "data_define.h"

class Solution
{
public:
    double myPow(double x, int n)
    {
        if (n == 1) {
            return x;
        } else if (n == -1) {
            return 1.0 / x;
        } else if (n == 0) {
            return 1.0;
        }
        unordered_map<int, double>::iterator mapIt = m_mapRet.find(n);
        if (mapIt != m_mapRet.end()) {
            double dTmp = mapIt->second;
            return dTmp;
        }
        int nTmp_1 = ceil(n / 2.0);
        int nTmp_2 = n - nTmp_1;
        double dRet_1 = myPow(x, nTmp_1);
        double dRet_2 = myPow(x, nTmp_2);
        double dRet = dRet_1 * dRet_2;
        m_mapRet[n] = dRet;
        return dRet;
    }

private:
    unordered_map<int, double> m_mapRet;
};

TEST(Solution, leetcode)
{
    EXPECT_DOUBLE_EQ(Solution().myPow(2.0, 10), 1024.0);
    EXPECT_DOUBLE_EQ(Solution().myPow(2.1, 3), 9.261);
    EXPECT_DOUBLE_EQ(Solution().myPow(2.0, -2), 0.25);
    EXPECT_DOUBLE_EQ(Solution().myPow(0.44528, 0), 1);
}

int main(int argc, char *argv[])
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
