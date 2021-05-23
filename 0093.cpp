#include "data_define.h"

class Solution
{
public:
    inline bool isValid(const std::string &str_data)
    {
        if (str_data.empty()) {
            return false;
        } else if (str_data.size() > 3) {
            return false;
        } else if (str_data.size() != 1 && str_data[0] == '0') {
            return false;
        } else {
            int nData = std::stoi(str_data);
            if (nData < 0 || nData > 255) {
                return false;
            }
        }
        return true;
    }

    vector<string> restoreIpAddresses(string s)
    {
        vector<string> vecResult;
        helper(vecResult, s, 0);
        return m_vecResult;
    }

    void helper(vector<string> &vec_result, const std::string &str_in, int n_idx)
    {
        if (vec_result.size() == 4) {
            if (n_idx == str_in.size()) {
                std::string strResult;
                for (size_t i = 0; i < vec_result.size(); i++) {
                    strResult += vec_result.at(i) + ".";
                }
                strResult.pop_back();
                m_vecResult.push_back(strResult);
            }
            return;
        } else if (vec_result.size() == 3 && str_in.size() - n_idx > 3) {
            return;
        } else {
            for (size_t j = 1; j < 4 && n_idx + j <= str_in.size(); j++) {
                std::string strTmp = str_in.substr(n_idx, j);
                if (!isValid(strTmp)) {
                    continue;
                }
                vec_result.push_back(strTmp);
                helper(vec_result, str_in, n_idx + j);
                vec_result.pop_back();
            }
        }
    }

private:
    vector<string> m_vecResult;
};

TEST(Solution, leetcode)
{
    string input;
    vector<string> output;
    vector<string> expected;

    input = "25525511135";
    output = Solution().restoreIpAddresses(input);
    expected = {"255.255.11.135", "255.255.111.35"};
    EXPECT_TRUE(output == expected)
        << "\ninput:   " << getString(input) << "\nouput:   " << getString(output)
        << "\nexpected:" << getString(expected);

    input = "0000";
    output = Solution().restoreIpAddresses(input);
    expected = {"0.0.0.0"};
    EXPECT_TRUE(output == expected)
        << "\ninput:   " << getString(input) << "\nouput:   " << getString(output)
        << "\nexpected:" << getString(expected);

    input = "1111";
    output = Solution().restoreIpAddresses(input);
    expected = {"1.1.1.1"};
    EXPECT_TRUE(output == expected)
        << "\ninput:   " << getString(input) << "\nouput:   " << getString(output)
        << "\nexpected:" << getString(expected);

    input = "010010";
    output = Solution().restoreIpAddresses(input);
    expected = {"0.10.0.10", "0.100.1.0"};
    EXPECT_TRUE(output == expected)
        << "\ninput:   " << getString(input) << "\nouput:   " << getString(output)
        << "\nexpected:" << getString(expected);

    input = "101023";
    output = Solution().restoreIpAddresses(input);
    expected = {"1.0.10.23", "1.0.102.3", "10.1.0.23", "10.10.2.3", "101.0.2.3"};
    EXPECT_TRUE(output == expected)
        << "\ninput:   " << getString(input) << "\nouput:   " << getString(output)
        << "\nexpected:" << getString(expected);
}

int main(int argc, char *argv[])
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
