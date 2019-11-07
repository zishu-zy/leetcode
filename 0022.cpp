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
    vector<string> generateParenthesis(int n)
    {
        vector<string> res;
        string tmp = "";
        helper(res, tmp, 0, 0, n);
        return res;
    }
    void helper(vector<string> &res, string &str, int l, int r, int n)
    {
        if (l == r && l == n) {
            res.push_back(str);
        }
        if (l < n) {
            str += '(';
            helper(res, str, l + 1, r, n);
            str.pop_back();
        }
        if (r < l) {
            str += ')';
            helper(res, str, l, r + 1, n);
            str.pop_back();
        }
    }
};

int main(void)
{
    Solution s;
    vector<string> tmp(s.generateParenthesis(4));
    for (int i = 0; i < (int)tmp.size(); ++i) {
        // std::cout << tmp[i] << " ";
        std::cout << tmp[i] << std::endl;
    }
    std::cout << std::endl;
    return 0;
}
