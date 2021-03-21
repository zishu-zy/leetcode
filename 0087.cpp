
#include "data_define.h"

class Solution
{
public:
    bool isScramble(string s1, string s2)
    {
        std::cout << "s1: " << s1 << " s2:" << s2 << std::endl;

        // if (s1.size() != s2.size()) {
        //     return false;
        // }

        if (s1 == s2) {
            return true;
        }
        for (size_t i = 1; i < s1.size(); i++) {
            // std::cout << "s1: " << s1.substr(0, i) << " s2:" << s2.substr(0, i) << std::endl;
            // std::cout << "s1: " << s1.substr(i) << " s2:" << s2.substr(i) << std::endl;
            // std::cout << "s1: " << s1.substr(0, i) << " s2:" << s2.substr(s2.size() - i)
            //           << std::endl;
            // std::cout << "s1: " << s1.substr(i) << " s2:" << s2.substr(0, s2.size() - i)
            //           << std::endl;
            // std::cout << "-------" << std::endl;
            if (isScramble(s1.substr(0, i), s2.substr(0, i)) &&
                isScramble(s1.substr(i), s2.substr(i))) {
                return true;
            }
            if (isScramble(s1.substr(0, i), s2.substr(s2.size() - i)) &&
                isScramble(s1.substr(i), s2.substr(0, s2.size() - i))) {
                return true;
            }
        }
        return false;
    }

private:
    std::vector<std::string> m_vecRetTmp;
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
    expected = true;
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
