
#include "data_define.h"

// 最快的
class Solution
{
public:
    string countAndSay(int n)
    {
        string s = "1";
        for (int i = 1; i < n; i++)
            s = generate(s);
        return s;
    }

private:
    string generate(string &last)
    {
        string rs;
        int len = last.size();
        int i = 0;
        while (i < len) {
            int j = i + 1;
            while (j < len && last[j] == last[i])
                j++;
            rs.push_back(j - i + '0');
            rs.push_back(last[i]);
            i = j;
        }
        return rs;
    }
};

// class Solution
// {
// public:
//     string countAndSay(int n)
//     {
//         string strRet = "1";
//         map<char, int> mapRet;
//         for (int i = 2; i <= n; ++i) {
//             string strTmp;
//             char charSingle = '0';
//             int nSingle = 0;
//             for (int j = 0; j < strRet.size(); ++j) {
//                 if (charSingle != strRet.at(j)) {
//                     if (charSingle != '0') {
//                         strTmp += std::to_string(nSingle) + charSingle;
//                     }
//                     charSingle = strRet.at(j);
//                     nSingle = 1;
//                 } else {
//                     nSingle++;
//                 }
//             }
//             if (charSingle != '0') {
//                 strTmp += std::to_string(nSingle) + charSingle;
//             }
//             strRet = strTmp;
//         }
//         return strRet;
//     }
// };

int stringToInteger(string input)
{
    return stoi(input);
}

int main()
{
    string line;
    while (getline(cin, line)) {
        int n = stringToInteger(line);

        string ret = Solution().countAndSay(n);

        string out = (ret);
        cout << out << endl;
    }
    return 0;
}
