/*
 * ==============================================================
 *
 *       FileName: 0029.cpp
 *    Description:
 *
 *         Author: zishu, zishuzy@gmail.com
 *        Created: 2019-11-06 09:43:50
 *  Last Modified: 2019-11-06 17:13:23
 *
 * ==============================================================
 */

#include <assert.h>
#include <limits.h>
#include <math.h>
#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>
#include <stack>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution
{
public:
    int divide(int dividend, int divisor)
    {
        long long d1 = dividend, d2 = divisor;
        long long ans = d1 / d2;
        if (ans > ((1LL << 31) - 1) || ans < -1LL * (1LL << 31))
            return (1LL << 31) - 1;
        return d1 / d2;

        // 我自己太挫了
        int result = 0;
        bool flag = true;
        if (divisor == 1) {
            return dividend;
        }
        if (dividend == -2147483648 && divisor == -1) {
            return 2147483647;
        } else if (dividend == -2147483648 && divisor == 2147483647) {
            return -1;
        }
        if (divisor == -2147483648) {
            if (dividend == -2147483648) {
                return 1;
            } else {
                return 0;
            }
        } else if (divisor == 2147483647) {
            if (dividend <= -2147483647) {
                return -1;
            } else if (dividend >= 2147483647) {
                return 1;
            } else {
                return 0;
            }
        } else if (divisor == -2147483647) {
            if (dividend <= -2147483647) {
                return 1;
            } else if (dividend >= 2147483647) {
                return -1;
            } else {
                return 0;
            }
        }
        if (dividend == -2147483648) {
            int dividend_tmp = 0;
            dividend_tmp = 1;
            flag = false;
            dividend = 2147483647;
            if (divisor < 0) {
                flag = !flag;
                divisor = -divisor;
            }
            while (dividend >= divisor) {
                int s = divisor;
                int add = 1;
                while (dividend >= (s << 1)) {
                    if (s >= 1073741823) {
                        break;
                    }
                    std::cout << "s:" << s << std::endl;
                    s <<= 1;
                    add <<= 1;
                }
                dividend -= s;
                result += add;
                if (dividend_tmp != 0) {
                    dividend += 1;
                    dividend_tmp = 0;
                }
            }
        } else {
            if (dividend < 0) {
                flag = false;
                dividend = -dividend;
            }
            if (divisor < 0) {
                flag = !flag;
                divisor = -divisor;
            }
            while (dividend >= divisor) {
                int s = divisor;
                int add = 1;
                while (dividend >= (s << 1)) {
                    if (s >= 1073741823) {
                        break;
                    }
                    std::cout << "s:" << s << std::endl;
                    s <<= 1;
                    add <<= 1;
                }
                dividend -= s;
                result += add;
            }
        }
        return flag ? result : -result;
    }
};

int stringToInteger(string input)
{
    return stoi(input);
}

int main()
{
    std::cout << (-1 >> 1) << std::endl;
    string line;
    while (getline(cin, line)) {
        int dividend = stringToInteger(line);
        getline(cin, line);
        int divisor = stringToInteger(line);

        int ret = Solution().divide(dividend, divisor);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
