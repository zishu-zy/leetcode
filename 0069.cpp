#include "data_define.h"

class Solution
{
public:
    int mySqrt(int x)
    {
        int nTmp = 1;
        if (x > 46340) {
            nTmp = 46340;
        }
        do {
            nTmp = (nTmp + x / nTmp) / 2;
        } while (nTmp * nTmp > x);
        return nTmp;
    }
};

TEST(Solution, leetcode)
{
    EXPECT_EQ(Solution().mySqrt(4), 2);
    EXPECT_EQ(Solution().mySqrt(8), 2);
    EXPECT_EQ(Solution().mySqrt(100), 10);
    EXPECT_EQ(Solution().mySqrt(200), 14);
    EXPECT_EQ(Solution().mySqrt(2147395599), 46339);
    EXPECT_EQ(Solution().mySqrt(2147483647), 46340);
}

int main(int argc, char *argv[])
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
