
#include "data_define.h"

// 也需要变通，加一和二分都有！！！
class Solution
{
public:
    bool search(vector<int> &nums, int target)
    {
        int n = nums.size() - 1;
        if (n == 0)
            return nums[0] == target ? true : false;
        int lo = 0;
        int hi = n;
        int mid;

        while (lo <= hi) {
            mid = lo + (hi - lo) / 2;
            if (nums[mid] == target)
                return true;

            // 分不清到底是前面有序还是后面有序，此时 start++ 即可,相当于去掉一个重复的干扰项
            if (nums[lo] == nums[mid]) {
                lo++;
                continue;
            }
            // 如果前半部分有序
            if (nums[lo] < nums[mid]) {
                // 如果target在前半部分
                if (nums[lo] <= target && target < nums[mid]) {
                    hi = mid - 1;
                } else {
                    lo = mid + 1;
                }
            }
            // 如果后半部分有序
            else {
                if (nums[mid] < target && target <= nums[hi]) {
                    lo = mid + 1;
                } else {
                    hi = mid - 1;
                }
            }
        }
        return false;
    }
};

class Solution_self
{
public:
    bool search_1(vector<int> &nums, int n_start, int n_end, int target)
    {
        int i = n_start;
        int j = n_end;
        int mid = i + (j - i) / 2;
        while (i <= j) {
            // std::cout << i << " " << mid << " " << j << std::endl;
            if (nums[mid] == target) {
                return true;
            } else if (nums[mid] > target) {
                j = mid - 1;
                mid = i + (j - i) / 2;
            } else {
                i = mid + 1;
                mid = i + (j - i) / 2;
            }
        }
        return false;
    }

    bool search_2(vector<int> &nums, int n_start, int n_end, int target)
    {
        if (n_start > n_end) {
            return false;
        }
        int i = n_start;
        int j = n_end;
        int mid = i + (j - i) / 2;
        if (nums[i] == target) {
            return true;
        }
        if (nums[j] == target) {
            return true;
        }
        if (nums[mid] == target) {
            return true;
        }

        if (nums[mid] > nums[i] || nums[mid] > nums[j]) {
            // i - mid: 必定升序
            if (nums[mid] > target && nums[i] < target) {
                return search_1(nums, i, mid - 1, target);
            } else {
                return search_2(nums, mid + 1, j, target);
            }
        }
        if (nums[mid] < nums[i] || nums[mid] < nums[j]) {
            // mid - j: 必定升序
            if (nums[mid] < target && nums[j] > target) {
                return search_1(nums, mid + 1, j, target);
            } else {
                return search_2(nums, i, mid - 1, target);
            }
        }
        bool bRet = search_2(nums, i, mid - 1, target);
        if (!bRet) {
            bRet = search_2(nums, mid + 1, j, target);
        }
        return bRet;
    }

    bool search(vector<int> &nums, int target)
    {
        if (nums.empty()) {
            return false;
        }
        return search_2(nums, 0, nums.size() - 1, target);
    }
};

TEST(Solution, leetcode)
{
    vector<int> input_1;
    int input_2;
    bool output;
    bool expected;

    input_1 = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1};
    input_2 = 2;
    output = Solution().search(input_1, input_2);
    expected = true;
    EXPECT_TRUE(output == expected) << "\ninput:   " << getString(input_1) << "\n"
                                    << getString(input_2) << "\nouput:   " << getString(output)
                                    << "\nexpected:" << getString(expected);

    input_1 = {1};
    input_2 = 1;
    output = Solution().search(input_1, input_2);
    expected = true;
    EXPECT_TRUE(output == expected) << "\ninput:   " << getString(input_1) << "\n"
                                    << getString(input_2) << "\nouput:   " << getString(output)
                                    << "\nexpected:" << getString(expected);

    input_1 = {1};
    input_2 = 0;
    output = Solution().search(input_1, input_2);
    expected = false;
    EXPECT_TRUE(output == expected) << "\ninput:   " << getString(input_1) << "\n"
                                    << getString(input_2) << "\nouput:   " << getString(output)
                                    << "\nexpected:" << getString(expected);

    input_1 = {0, 0, 1, 2, 2, 5, 6};
    input_2 = 6;
    output = Solution().search(input_1, input_2);
    expected = true;
    EXPECT_TRUE(output == expected) << "\ninput:   " << getString(input_1) << "\n"
                                    << getString(input_2) << "\nouput:   " << getString(output)
                                    << "\nexpected:" << getString(expected);

    input_1 = {2, 5, 6, 0, 0, 1, 2};
    input_2 = 0;
    output = Solution().search(input_1, input_2);
    expected = true;
    EXPECT_TRUE(output == expected) << "\ninput:   " << getString(input_1) << "\n"
                                    << getString(input_2) << "\nouput:   " << getString(output)
                                    << "\nexpected:" << getString(expected);

    input_1 = {2, 5, 6, 0, 0, 1, 2};
    input_2 = 3;
    output = Solution().search(input_1, input_2);
    expected = false;
    EXPECT_TRUE(output == expected) << "\ninput:   " << getString(input_1) << "\n"
                                    << getString(input_2) << "\nouput:   " << getString(output)
                                    << "\nexpected:" << getString(expected);
}

int main(int argc, char *argv[])
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
