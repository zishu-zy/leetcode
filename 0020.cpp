#include <algorithm>
#include <assert.h>
#include <fstream>
#include <iostream>
#include <limits.h>
#include <math.h>
#include <sstream>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution
{
public:
    bool isValid(string s)
    {
        vector<char> arr1{'(', '[', '{'};
        vector<char> arr2{')', ']', '}'};
        stack<char> st;
        char tmp;
        for (string::iterator it = s.begin(); it != s.end(); ++it) {
            for (int i = 0; i < 3; ++i) {
                if (*it == arr2[i]) {
                    if (st.empty()) {
                        return false;
                    }
                    tmp = st.top();
                    st.pop();
                    if (tmp != arr1[i]) {
                        return false;
                    }
                } else if (*it == arr1[i]) {
                    st.push(*it);
                }
            }
        }
        if (!st.empty()) {
            return false;
        }
        return true;
    }
};

string stringToString(string input)
{
    assert(input.length() >= 2);
    string result;
    for (int i = 1; i < (int)input.length() - 1; i++) {
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

string boolToString(bool input)
{
    return input ? "True" : "False";
}

int main()
{
    string line;
    while (getline(cin, line)) {
        string s = stringToString(line);

        bool ret = Solution().isValid(s);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}
