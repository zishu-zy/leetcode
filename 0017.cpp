#include <algorithm>
#include <fstream>
#include <iostream>
#include <limits.h>
#include <math.h>
#include <sstream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

void split(const std::string &s, const char delim, std::vector<int> &sv)
{
    sv.clear();
    std::istringstream iss(s);
    std::string temp;
    while (std::getline(iss, temp, delim)) {
        if (temp.empty())
            continue;
        sv.emplace_back(std::move(atoi(temp.c_str())));
    }
    return;
}

std::string readFile(const std::string &file)
{
    std::fstream in(file);
    std::istreambuf_iterator<char> beg(in), end;
    std::string strdata(beg, end);
    in.close();
    return strdata;
}

class Solution
{
public:
    vector<string> letterCombinations(string digits)
    {
        vector<vector<char>> arr(8);
        arr[0] = vector<char>{'a', 'b', 'c'};
        arr[1] = vector<char>{'d', 'e', 'f'};
        arr[2] = vector<char>{'g', 'h', 'i'};
        arr[3] = vector<char>{'j', 'k', 'l'};
        arr[4] = vector<char>{'m', 'n', 'o'};
        arr[5] = vector<char>{'p', 'q', 'r', 's'};
        arr[6] = vector<char>{'t', 'u', 'v'};
        arr[7] = vector<char>{'w', 'x', 'y', 'z'};
        vector<string> result;
        vector<int> nums;
        int num;
        for (string::iterator it = digits.begin(); it != digits.end(); ++it) {
            num = stoi(string(1, *it));
            nums.push_back(num - 2);
        }
        int len = nums.size();
        int reslen;
        for (int i = 0; i < len; ++i) {
            if (result.empty()) {
                for (int j = 0; j < (int)arr[nums[i]].size(); ++j) {
                    result.push_back(string(1, arr[nums[i]][j]));
                }
            } else {
                reslen = result.size();
                for (int j = 0; j < reslen; ++j) {
                    for (int z = 0; z < (int)arr[nums[i]].size(); ++z) {
                        result.push_back(result[j] + arr[nums[i]][z]);
                    }
                }
                result.erase(result.begin(), result.begin() + reslen);
            }
        }
        return result;
    }
};

int main(void)
{
    Solution s;
    std::string strdata = readFile("input.txt");
    vector<string> r(s.letterCombinations("22"));
    for (int i = 0; i < (int)r.size(); ++i) {
        std::cout << r[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}
