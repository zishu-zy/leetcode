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
    int threeSumClosest(vector<int> &nums, int target)
    {
        int result = 0;
        int minErr = INT_MAX;
        sort(nums.begin(), nums.end());
        // for (int i = 0; i < (int)nums.size(); ++i) {
        //     std::cout << nums[i] << " ";
        // }
        // std::cout << std::endl;
        int len = nums.size();
        int aid = 0;
        int bid = 0;
        int cid = 0;
        int sum = 0;
        // a指针从左进行扫描
        for (aid = 0; aid < len - 2; ++aid) {
            bid = aid + 1;
            cid = len - 1;
            // 去除重复
            if (aid > 0 && nums[aid] == nums[aid - 1]) {
                continue;
            }
            while (bid < cid) {
                sum = nums[aid] + nums[bid] + nums[cid];
                if (sum > target) {
                    if (abs(sum - target) < minErr) {
                        result = sum;
                        minErr = abs(sum - target);
                    }
                    --cid;
                    while (bid < cid && nums[cid] == nums[cid + 1]) {
                        --cid;
                    }
                } else if (sum < target) {
                    if (abs(target - sum) < minErr) {
                        result = sum;
                        minErr = abs(sum - target);
                    }
                    ++bid;
                    while (bid < cid && nums[bid] == nums[bid - 1]) {
                        ++bid;
                    }
                } else {
                    return target;
                }
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
    int result = s.threeSumClosest(nums, 1);
    std::cout << result << std::endl;
    return 0;
}
