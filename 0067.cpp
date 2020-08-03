
#include "data_define.h"

// 简洁的 - 还可以优化
class Solution
{
public:
    string addBinary(string a, string b)
    {
        int i = a.size() - 1, j = b.size() - 1;
        int carryIn = 0;
        string ans = "";
        while (i >= 0 || j >= 0 || carryIn) {
            int res = carryIn;
            if (i >= 0) {
                res += (a[i] - '0');
                --i;
            }
            if (j >= 0) {
                res += (b[j] - '0');
                --j;
            }
            carryIn = res / 2;
            ans.push_back('0' + res % 2);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

class Solution2
{
public:
    string addBinary(string a, string b)
    {
        std::string strRet;
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        int nALen = a.size();
        int nBLen = b.size();
        int nLen = max(nALen, nBLen);
        char chTmp = '0';
        char chCarry = '0';
        for (int i = 0; i < nLen; ++i) {
            if (chCarry == '0') {
                if (i >= nALen) {
                    strRet.append(b.begin() + i, b.end());
                    break;
                } else if (i >= nBLen) {
                    strRet.append(a.begin() + i, a.end());
                    break;
                }
            }
            chTmp = chCarry;
            if (i < nALen) {
                chTmp += a[i] - '0';
            }
            if (i < nBLen) {
                chTmp += b[i] - '0';
            }
            if (chTmp > '1') {
                chCarry = '1';
                chTmp -= 2;
            } else {
                chCarry = '0';
            }
            strRet.push_back(chTmp);
        }
        if (chCarry != '0') {
            strRet.push_back(chCarry);
        }
        reverse(strRet.begin(), strRet.end());
        return strRet;
    }
};

TEST(Solution, leetcode)
{
    std::string strOutput;
    std::string strExpected;

    strOutput = Solution().addBinary("1111", "1111");
    strExpected = "11110";
    EXPECT_EQ(strOutput, strExpected);

    strOutput = Solution().addBinary("11", "1");
    strExpected = "100";
    EXPECT_EQ(strOutput, strExpected);

    strOutput = Solution().addBinary("1010", "1011");
    strExpected = "10101";
    EXPECT_EQ(strOutput, strExpected);

    strOutput = Solution().addBinary("1111110", "1");
    strExpected = "1111111";
    EXPECT_EQ(strOutput, strExpected);
}

int main(int argc, char *argv[])
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
