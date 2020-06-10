
#include "data_define.h"

class Solution
{
public:
    int lengthOfLastWord(string s)
    {
        if (s.empty()) {
            return 0;
        }
        int nRet = 0;
        int nLen = s.size();
        for (int i = nLen - 1; i >= 0; --i) {
            if (s.at(i) == ' ') {
                if (nRet != 0) {
                    break;
                }
            } else {
                ++nRet;
            }
        }
        return nRet;
    }
};

TEST(Solution, leetcode)
{
    EXPECT_EQ(Solution().lengthOfLastWord("a "), 1);
    EXPECT_EQ(Solution().lengthOfLastWord("Hello World"), 5);
    EXPECT_EQ(Solution().lengthOfLastWord("world"), 5);
}

int main(int argc, char *argv[])
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
