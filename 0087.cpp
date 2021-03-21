
#include "data_define.h"

class Solution
{
public:
    bool isScramble(string s1, string s2)
    {
        if (s1 == s2) {
            return true;
        }
        auto it = m_mapTmp.find(s1 + s2);
        if (it != m_mapTmp.end()) {
            return it->second;
        }
        bool bRet = false;
        for (size_t i = 1; i < s1.size(); i++) {
            if (isScramble(s1.substr(0, i), s2.substr(0, i)) &&
                isScramble(s1.substr(i), s2.substr(i))) {
                bRet = true;
                break;
            }
            if (isScramble(s1.substr(0, i), s2.substr(s2.size() - i)) &&
                isScramble(s1.substr(i), s2.substr(0, s2.size() - i))) {
                bRet = true;
                break;
            }
        }
        m_mapTmp[s1 + s2] = bRet;
        return bRet;
    }

private:
    std::map<std::string, bool> m_mapTmp;
};

TEST(Solution, leetcode)
{
    std::string input_1;
    std::string input_2;
    bool output;
    bool expected;

    input_1 = "abcdefghijklmnopq";
    input_2 = "efghijklmnopqcadb";
    output = Solution().isScramble(input_1, input_2);
    expected = false;
    EXPECT_TRUE(output == expected)
        << "\ninput:   " << getString(input_1) << "\n         " << getString(input_2)
        << "\nouput:   " << getString(output) << "\nexpected:" << getString(expected);

    input_1 = "abcde";
    input_2 = "decab";
    output = Solution().isScramble(input_1, input_2);
    expected = true;
    EXPECT_TRUE(output == expected)
        << "\ninput:   " << getString(input_1) << "\n         " << getString(input_2)
        << "\nouput:   " << getString(output) << "\nexpected:" << getString(expected);

    // input_1 = "abcde";
    // input_2 = "caebd";
    // output = Solution().isScramble(input_1, input_2);
    // expected = false;
    // EXPECT_TRUE(output == expected)
    //     << "\ninput:   " << getString(input_1) << "\n         " << getString(input_2)
    //     << "\nouput:   " << getString(output) << "\nexpected:" << getString(expected);

    input_1 = "great";
    input_2 = "rgeat";
    output = Solution().isScramble(input_1, input_2);
    expected = true;
    EXPECT_TRUE(output == expected)
        << "\ninput:   " << getString(input_1) << "\n         " << getString(input_2)
        << "\nouput:   " << getString(output) << "\nexpected:" << getString(expected);
}

int main(int argc, char *argv[])
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
