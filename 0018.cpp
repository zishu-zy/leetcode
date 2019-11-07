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
    vector<vector<int>> threeSum(vector<int> &nums, int s, int target)
    {
        vector<vector<int>> result;
        int len = nums.size();
        int aid = 0;
        int bid = 0;
        int cid = 0;
        int sum3 = 0;
        // a指针从左进行扫描
        for (aid = s; aid < len - 2; ++aid) {
            bid = aid + 1;
            cid = len - 1;
            // 去除重复
            if (aid > s && nums[aid] == nums[aid - 1]) {
                continue;
            }
            // 避免数组中数太大了
            // if (nums[aid] + nums[aid + 1] + nums[aid + 2] > target) {
            //     break;
            // }
            // 避免数组中数太小了
            // if (nums[cid] + nums[cid - 1] + nums[cid - 2] < target) {
            //     break;
            // }
            // 避免左侧的太小了
            // if (nums[aid] + nums[cid] + nums[cid - 1] < target) {
            //     continue;
            // }
            while (bid < cid) {
                sum3 = nums[aid] + nums[bid] + nums[cid];
                if (sum3 > target) {
                    --cid;
                    while (bid < cid && nums[cid] == nums[cid + 1]) {
                        --cid;
                    }
                } else if (sum3 < target) {
                    ++bid;
                    while (bid < cid && nums[bid] == nums[bid - 1]) {
                        ++bid;
                    }
                } else {
                    result.push_back(
                        vector<int>{nums[aid], nums[bid], nums[cid]});
                    bid++;
                    cid--;
                    while (bid < cid && nums[cid] == nums[cid + 1]) {
                        --cid;
                    }
                    while (bid < cid && nums[bid] == nums[bid - 1]) {
                        ++bid;
                    }
                }
            }
        }
        return result;
    }
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        vector<vector<int>> result;
        vector<vector<int>> threeRes;
        sort(nums.begin(), nums.end());
        // for (int i = 0; i < (int)nums.size(); ++i) {
        //     std::cout << nums[i] << " ";
        // }
        // std::cout << std::endl;
        int len = nums.size();
        for (int i = 0; i < len; ++i) {
            // 去除重复
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            threeRes = threeSum(nums, i + 1, target - nums[i]);
            for (int j = 0; j < (int)threeRes.size(); ++j) {
                threeRes[j].push_back(nums[i]);
                result.push_back(threeRes[j]);
            }
        }
        return result;
    }
};

int main(void)
{
    Solution s;
    std::string strdata = readFile("input.txt");
    std::vector<int> nums;
    split(strdata, ',', nums);
    vector<vector<int>> result = s.fourSum(nums, 4);
    for (int i = 0; i < (int)result.size(); ++i) {
        for (int j = 0; j < (int)result[i].size(); ++j) {
            std::cout << result[i][j] << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}
