
#include "data_define.h"

using namespace std;
/*
    int search(vector<int> &nums, int target)
    {
        if (nums.size() == 0)
            return -1;
        int left = 0, right = (int)nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                return mid;
            }
            if (nums[left] <= nums[mid]) {
                if (nums[left] <= target && target < nums[mid]) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            } else {
                if (nums[mid] < target && target <= nums[right]) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
        }
        return -1;
    }
*/
class Solution
{
public:
    int search(vector<int> &nums, int target)
    {

        int nRet = -1;
        if (nums.empty()) {
            return nRet;
        }
        int len = nums.size();
        int nLeft = 0;
        int nRight = len - 1;
        int nMid = (nLeft + nRight) / 2;
        int nLeftValue = nums[nLeft];
        int nRightValue = nums[nRight];
        bool bChange = true;
        if (nLeftValue <= nRightValue) {
            bChange = false;
        }
        if (target == nLeftValue) {
            return nLeft;
        } else if (target == nRightValue) {
            return nRight;
        }
        if (target < nRightValue) {
            std::cout << "right" << std::endl;
            while (nLeft <= nRight) {
                std::cout << nLeft << " " << nMid << " " << nRight << std::endl;
                if (bChange && nums[nMid] > nLeftValue) {
                    nLeft = nMid + 1;
                } else if (nums[nMid] > target) {
                    nRight = nMid - 1;
                } else if (nums[nMid] < target) {
                    nLeft = nMid + 1;
                } else if (nums[nMid] == target) {
                    nRet = nMid;
                    break;
                }
                nMid = (nLeft + nRight + 1) / 2;
            }
        } else if (target > nLeftValue) {
            std::cout << "left" << std::endl;
            while (nLeft <= nRight) {
                std::cout << nLeft << " " << nMid << " " << nRight << std::endl;
                if (bChange && nums[nMid] < nLeftValue) {
                    nRight = nMid - 1;
                } else if (nums[nMid] > target) {
                    nRight = nMid - 1;
                } else if (nums[nMid] < target) {
                    nLeft = nMid + 1;
                } else if (nums[nMid] == target) {
                    nRet = nMid;
                    break;
                }
                nMid = (nLeft + nRight + 1) / 2;
            }
        }
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
    string line;
    while (getline(cin, line)) {
        vector<int> nums = stringToIntegerVector(line);
        getline(cin, line);
        int target = stringToInteger(line);

        int ret = Solution().search(nums, target);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
