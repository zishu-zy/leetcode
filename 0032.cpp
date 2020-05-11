
#include "data_define.h"

// 最快的
class Solution
{
public:
    int longestValidParentheses(string s)
    {
        stack<int> stac;
        stac.push(-1);
        int maxLen = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') {
                stac.push(i);
            } else {
                stac.pop();
                if (stac.empty()) {
                    stac.push(i);
                } else {
                    maxLen = max(maxLen, i - stac.top());
                }
            }
        }
        return maxLen;
    }
};

// class Solution
// {
// public:
//     int longestValidParentheses(string s)
//     {
//         int nLen = s.size();
//         if (nLen == 0 || nLen == 1) {
//             return 0;
//         }
//         int nLeftCount = 0;
//         int nRightCount = 0;
//         std::vector<int> vecRets(nLen, 0);
//         for (int i = 0; i < nLen; ++i) {
//             if (s.at(i) == '(') {
//                 ++nLeftCount;
//             } else if (nLeftCount != 0) {
//                 ++nRightCount;
//             }
//             if (nLeftCount != 0 && nRightCount != 0) {
//                 --nLeftCount;
//                 --nRightCount;
//                 vecRets[i] = 1;
//             }
//         }
//         std::stack<int> stkZero;
//         for (int i = 0; i < nLen; ++i) {
//             if (vecRets.at(i) == 0) {
//                 stkZero.push(i);
//             } else if (!stkZero.empty()) {
//                 vecRets[stkZero.top()] = 1;
//                 stkZero.pop();
//             }
//         }
//         int nRet = 0;
//         int nOneCount = 0;
//         for (int i = 0; i < nLen; ++i) {
//             if (vecRets.at(i) == 1) {
//                 ++nOneCount;
//             } else {
//                 if (nOneCount > nRet) {
//                     nRet = nOneCount;
//                 }
//                 nOneCount = 0;
//             }
//         }
//         if (nOneCount > nRet) {
//             nRet = nOneCount;
//         }
//         return nRet;
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
        string s = stringToString(line);

        int ret = Solution().longestValidParentheses(s);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
