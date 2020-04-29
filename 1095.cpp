
#include "data_define.h"

static int getCount = 0;

class MountainArray
{
public:
    int get(int index) { return data.at(index); }
    int length() { return data.size(); }
    vector<int> data;
};

/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution
{
public:
    int helper_1(int target, int n_begin, int n_end, MountainArray &mountainArr)
    {
        int nMid = n_begin + (n_end - n_begin) / 2;
        if (nMid == n_begin) {
            getCount++;
            if (mountainArr.get(n_begin) == target) {
                return n_begin;
            } else if (mountainArr.get(n_end) == target) {
                return n_end;
            }
            return -1;
        }

        int nRetMid = -1;
        int nRet1 = -1;
        int nRet2 = -1;
        getCount += 3;
        int nLeftValue = mountainArr.get(nMid - 1);
        int nRightValue = mountainArr.get(nMid + 1);
        int nMidValue = mountainArr.get(nMid);

        if (nLeftValue < nMidValue && nMidValue < nRightValue) {
            // 左侧
            if (nLeftValue == target) {
                return nMid - 1;
            } else if (nMidValue == target) {
                return nMid;
            } else if (nRightValue == target) {
                return nMid + 1;
            }
            nRet1 = helper_2(target, n_begin, nMid - 2, mountainArr);
            if (nRet1 != -1) {
                return nRet1;
            }
            nRet2 = helper_1(target, nMid + 2, n_end, mountainArr);
        } else if (nLeftValue > nMidValue && nMidValue > nRightValue) {
            // 右侧
            nRet1 = helper_1(target, n_begin, nMid - 2, mountainArr);
            if (nRet1 != -1) {
                return nRet1;
            }
            if (nLeftValue == target) {
                nRet2 = nMid - 1;
            } else if (nMidValue == target) {
                nRet2 = nMid;
            } else if (nRightValue == target) {
                nRet2 = nMid + 1;
            } else {
                nRet2 = helper_2(target, nMid + 2, n_end, mountainArr, false);
            }
        } else {
            // 中间
            if (nLeftValue == target) {
                return nMid - 1;
            } else if (nRightValue == target) {
                nRet1 = helper_2(target, n_begin, nMid - 2, mountainArr);
                nRet2 = nMid + 1;
            } else if (nMidValue == target) {
                nRet1 = nMid;
            } else {
                nRet1 = helper_2(target, n_begin, nMid - 2, mountainArr);
                if (nRet1 != -1) {
                    return nRet1;
                }
                nRet2 = helper_2(target, nMid + 2, n_end, mountainArr, false);
            }
        }
        return nRet1 != -1 ? nRet1 : nRet2;
    }

    int helper_2(int target, int n_begin, int n_end, MountainArray &mountainArr,
                 bool b_flag = true)
    {
        if (n_begin >= 0 && n_begin < mountainArr.length() && n_end >= 0 &&
            n_end < mountainArr.length()) {
            getCount += 2;
            int nLeftValue = mountainArr.get(n_begin);
            int nRightValue = mountainArr.get(n_end);
            if (nLeftValue == target) {
                return n_begin;
            } else if (nRightValue == target) {
                return n_end;
            } else {
                if (b_flag) {
                    if (nRightValue < target || nLeftValue > target) {
                        return -1;
                    }
                } else {
                    if (nRightValue > target || nLeftValue < target) {
                        return -1;
                    }
                }
            }
        }
        int nBegin = n_begin + 1;
        int nEnd = n_end - 1;
        while (nBegin <= nEnd) {
            getCount++;
            int nMid = nBegin + (nEnd - nBegin) / 2;
            int nMidValue = mountainArr.get(nMid);
            if (nMidValue == target) {
                return nMid;
            } else if (b_flag) {
                if (nMidValue < target) {
                    nBegin = nMid + 1;
                } else if (nMidValue > target) {
                    nEnd = nMid - 1;
                }
            } else {
                if (nMidValue > target) {
                    nBegin = nMid + 1;
                } else if (nMidValue < target) {
                    nEnd = nMid - 1;
                }
            }
        }
        return -1;
    }

    int findInMountainArray(int target, MountainArray &mountainArr)
    {
        int nRet = helper_1(target, 0, mountainArr.length() - 1, mountainArr);
        return nRet;
    }
};

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

int stringToInteger(string input)
{
    return stoi(input);
}

int main()
{
    string line = "[1,5,2]";
    vector<int> secret = stringToIntegerVector(line);
    line = "0";
    int target = stringToInteger(line);
    MountainArray arr;
    arr.data = secret;
    int ret = Solution().findInMountainArray(target, arr);

    string out = to_string(ret);
    cout << out << endl;

    std::cout << "getCount: " << getCount << std::endl;
    return 0;
}
