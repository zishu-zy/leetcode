
#include "data_define.h"

// 最快的
class Solution
{
public:
    string multiply(string num1, string num2)
    {
        int m = num1.size(), n = num2.size();
        vector<int> res(m + n, 0);
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                int mul = (num1[i] - '0') * (num2[j] - '0');
                int p1 = i + j;     // p1为进位位置
                int p2 = i + j + 1; // p2为乘积位置
                int sum = mul + res[p2];
                res[p2] = sum % 10;
                res[p1] += sum / 10;
            }
        }
        int i = 0;
        while (i < res.size() && res[i] == 0) {
            i++; // 去零
        }
        string str;
        for (; i < res.size(); i++) {
            str.push_back(res[i] + '0'); //转字符串
        }
        return str.size() == 0 ? "0" : str;
    }
};

// class Solution
// {
// public:
//     string multiply(string num1, string num2)
//     {
//         if (num1.empty() || num2.empty()) {
//             return "";
//         } else if (num1.at(0) == '0' || num2.at(0) == '0') {
//             return "0";
//         }
//         string strRet;
//         int nLen1 = num1.size();
//         int nLen2 = num2.size();
//         vector<string> vecRet(nLen1, "");
//         int nMax = 0;
//         int nCarryBit;
//         for (int i = nLen1 - 1; i >= 0; --i) {
//             string strTmpRet;
//             int nCount = 0;
//             for (int j = 0; j < nLen1 - i - 1; ++j) {
//                 strTmpRet += "0";
//                 nCount++;
//             }
//             nCarryBit = 0;
//             for (int j = nLen2 - 1; j >= 0; --j) {
//                 int nTmp = (num1.at(i) - '0') * (num2.at(j) - '0') +
//                 nCarryBit; nCarryBit = nTmp / 10; nTmp = nTmp % 10; strTmpRet
//                 += std::to_string(nTmp); nCount++;
//             }
//             if (nCarryBit != 0) {
//                 strTmpRet += std::to_string(nCarryBit);
//                 nCount++;
//             }
//             vecRet[i] = strTmpRet;
//             if (nCount > nMax) {
//                 nMax = nCount;
//             }
//         }
//         nCarryBit = 0;
//         for (int i = 0; i < nMax; ++i) {
//             int nTmp = nCarryBit;
//             for (int j = 0; j < vecRet.size(); ++j) {
//                 if (i < vecRet.at(j).size()) {
//                     nTmp += vecRet.at(j).at(i) - '0';
//                 }
//             }
//             nCarryBit = nTmp / 10;
//             nTmp = nTmp % 10;
//             strRet = std::to_string(nTmp) + strRet;
//         }
//         if (nCarryBit != 0) {
//             strRet = std::to_string(nCarryBit) + strRet;
//         }
//         return strRet;
//     }
// };

string stringToString(string input)
{
    assert(input.length() >= 2);
    string result;
    for (int i = 1; i < input.length() - 1; i++) {
        char currentChar = input[i];
        if (input[i] == '\\') {
            char nextChar = input[i + 1];
            switch (nextChar) {
            case '\"':
                result.push_back('\"');
                break;
            case '/':
                result.push_back('/');
                break;
            case '\\':
                result.push_back('\\');
                break;
            case 'b':
                result.push_back('\b');
                break;
            case 'f':
                result.push_back('\f');
                break;
            case 'r':
                result.push_back('\r');
                break;
            case 'n':
                result.push_back('\n');
                break;
            case 't':
                result.push_back('\t');
                break;
            default:
                break;
            }
            i++;
        } else {
            result.push_back(currentChar);
        }
    }
    return result;
}

int main()
{
    string line;
    while (getline(cin, line)) {
        string num1 = stringToString(line);
        getline(cin, line);
        string num2 = stringToString(line);

        string ret = Solution().multiply(num1, num2);

        string out = (ret);
        cout << out << endl;
    }
    return 0;
}
