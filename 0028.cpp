#include <algorithm>
#include <assert.h>
#include <fstream>
#include <iostream>
#include <limits.h>
#include <math.h>
#include <sstream>
#include <stack>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

// class Solution
// {
// public:
//     int strStr(string haystack, string needle)
//     {
//         if (needle.size() == 0)
//             return 0;
//         if (needle.size() > haystack.size())
//             return -1;
//         int i, j, k;
//         for (i = 0; i <= haystack.size() - needle.size(); i++) {
//             if (haystack[i] != needle[0])
//                 continue;
//             k = i;
//             i++;
//             for (j = 1; j < needle.size() && i < haystack.size(); j++, i++) {
//                 if (haystack[i] != needle[j])
//                     break;
//             }
//             if (j == needle.size())
//                 return k;
//             else {
//                 i = k;
//                 continue;
//             }
//         }
//         return -1;
//     }
// };

class Solution
{
public:
    int strStr(string haystack, string needle)
    {
        int result = -1;
        int hlen = haystack.size();
        int nlen = needle.size();
        if (needle.empty()) {
            return 0;
        }
        if (hlen < nlen) {
            return -1;
        }
        bool flag = true;
        for (int i = 0; i <= (hlen - nlen); ++i) {
            flag = true;
            for (int j = 0; j < nlen; ++j) {
                if (haystack[i + j] != needle[j]) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                result = i;
                break;
            }
        }
        return result;
    }
};

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
        string haystack = stringToString(line);
        getline(cin, line);
        string needle = stringToString(line);

        int ret = Solution().strStr(haystack, needle);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
