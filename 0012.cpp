/*
 * ==============================================================
 *
 *       FileName: 0012.cpp
 *    Description:
 *
 *         Author: zhaiyu, zishuzy@gmail.com
 *        Created: 2018-12-30 11:16:55
 *  Last Modified: 2018-12-30 13:31:10
 *
 *  Copyright (C) 2018 zhaiyu. All rights reserved.
 *
 * ==============================================================
 */

#include <algorithm>
#include <cassert>
#include <gtest/gtest.h>
#include <iostream>
#include <limits.h>
#include <sstream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution
{
public:
    string intToRoman(int num)
    {        
        int values[]={1000,900,500,400,100,90,50,40,10,9,5,4,1};
        string reps[]={"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        
        string res;
        for(int i=0; i<13; i++){
            while(num>=values[i]){
                num -= values[i];
                res += reps[i];
            }
        }
        return res;

        // 我的方式
        // int di[] = {1000, 500, 100, 50, 10, 5, 1, 0, 0};
        // char ds[] = {'M', 'D', 'C', 'L', 'X', 'V', 'I', ' ', ' '};
        // int i = 0;
        // int tmp = 100;
        // int tmp_i = 2;
        // string result;
        // while (num > 0) {
        //     if (num >= di[i]) {
        //         result.push_back(ds[i]);
        //         num -= di[i];
        //     } else {
        //         if (num >= di[i] - tmp) {
        //             result.push_back(ds[tmp_i]);
        //             result.push_back(ds[i]);
        //             num -= (di[i] - tmp);
        //         } else {
        //             i++;
        //             if (di[i] <= tmp) {
        //                 tmp /= 10;
        //                 tmp_i += 2;
        //             }
        //         }
        //     }
        // }
        // return result;
    }
};

int stringToInteger(string input)
{
    return stoi(input);
}

int main()
{
    string line;
    while (getline(cin, line)) {
        int num = stringToInteger(line);

        string ret = Solution().intToRoman(num);

        string out = (ret);
        cout << out << endl;
    }
    return 0;
}
