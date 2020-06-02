
#include "data_define.h"

// 最快的
class Solution
{
public:
    //输入: [1,2,1,3,2,5]
    //输出: [3,5]
    vector<int> singleNumbers(vector<int> &nums)
    {
        int s = 0;
        for (int num : nums) {
            s ^= num;
        }
        // s是只出现一次的2个数字的^ 记做数字a,b
        // 既然a,b
        // 不一样，那么s肯定不是0，那么s的二进制肯定至少有1位（第n位）是1，只有0^1才等于1
        // 所以a,b 在第n位，要么a是0，b是1 ，要么b是0，a是1    ---->A
        // s = 3 ^ 5; 0x0011 ^ 0x0101 = 0x0110 = 6
        //假设int是8位
        //-6  原码1000 0110
        //    反码1111 0001
        //    补码1111 0010
        // s & (-s)
        //  0000 0110
        //& 1111 0010
        //  0000 0010
        //所以k = s & (-s) 就是保留s的最后一个1，并且将其他位变为0
        //也就是s最后一个1是倒数第二位   --->B 根据A和B  我们可以将数组分为2组
        //将倒数第二位 为0的分为第一组
        int k = s & (-s);
        // 1  0001  第一组
        // 2  0010  第二组
        // 1  0001  第一组
        // 3  0011  第二组
        // 2  0010  第二组
        // 5  0101  第一组
        //第一组 1 1 5  第二组 2 3 2 这样我们就将2个只有一个的数
        //分到了2个数组里了
        vector<int> rs(2, 0);
        for (int num : nums) {
            if (num & k) {
                //第二组
                rs[0] ^= num;
            } else {
                //第一组
                rs[1] ^= num;
            }
        }
        return rs;
    }
};

// 自己的
// class Solution
// {
// public:
//     vector<int> singleNumbers(vector<int> &nums)
//     {
//         vector<int> vecRet;
//         int nCount = nums.size();
//         if (nCount == 0) {
//             return vecRet;
//         }
//         int nTmp = 0;
//         for (int i = 0; i < nCount; ++i) {
//             nTmp ^= nums[i];
//         }
//         int nIndex = 0;
//         while ((nTmp & 0x01) == 0) {
//             nTmp = nTmp >> 1;
//             nIndex++;
//         }
//         int nR1 = 0;
//         int nR2 = 0;
//         for (int i = 0; i < nCount; ++i) {
//             if (((nums[i] >> nIndex) & 0x01) == 0) {
//                 nR1 ^= nums[i];
//             } else {
//                 nR2 ^= nums[i];
//             }
//         }
//         vecRet.push_back(nR1);
//         vecRet.push_back(nR2);
//         return vecRet;
//     }
// };

void trimLeftTrailingSpaces(string &input)
{
    input.erase(input.begin(), find_if(input.begin(), input.end(),
                                       [](int ch) { return !isspace(ch); }));
}

void trimRightTrailingSpaces(string &input)
{
    input.erase(find_if(input.rbegin(), input.rend(),
                        [](int ch) { return !isspace(ch); })
                    .base(),
                input.end());
}

vector<int> stringToIntegerVector(string input)
{
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(stoi(item));
    }
    return output;
}

string integerVectorToString(vector<int> list, int length = -1)
{
    if (length == -1) {
        length = list.size();
    }

    if (length == 0) {
        return "[]";
    }

    string result;
    for (int index = 0; index < length; index++) {
        int number = list[index];
        result += to_string(number) + ", ";
    }
    return "[" + result.substr(0, result.length() - 2) + "]";
}

int main()
{
    string line;
    while (getline(cin, line)) {
        vector<int> nums = stringToIntegerVector(line);

        vector<int> ret = Solution().singleNumbers(nums);

        string out = integerVectorToString(ret);
        cout << out << endl;
    }
    return 0;
}
