
#include "data_define.h"

// 最快的 - 感觉一样的，为啥这么大差距
class Solution
{
public:
    vector<vector<int>> permuteUnique(vector<int> &nums)
    {
        vector<vector<int>> result;
        int len = nums.size();
        if (len == 0)
            return result;
        vector<int> tmp;
        vector<int> visited(len, 0);
        sort(nums.begin(), nums.end());
        backtrack(result, tmp, nums, visited, len);
        return result;
    }
    void backtrack(vector<vector<int>> &result, vector<int> &tmp,
                   vector<int> &nums, vector<int> &visited, int len)
    {
        if (tmp.size() == len) {
            result.push_back(tmp);
            return;
        }
        for (int i = 0; i < len; ++i) {
            if (visited[i] == 1 ||
                (i > 0 && nums[i] == nums[i - 1] && visited[i - 1] == 0))
                continue;
            visited[i] = 1;
            tmp.push_back(nums[i]);
            backtrack(result, tmp, nums, visited, len);
            tmp.pop_back();
            visited[i] = 0;
        }
    }
};

// class Solution
// {
// public:
//     void dfs(vector<int> &nums, vector<int> &path)
//     {
//         int path_size = path.size();
//         int nums_size = nums.size();
//         if (path_size == nums_size) {
//             m_verPath.push_back(path);
//             return;
//         }
//         for (int i = 0; i < nums_size; ++i) {
//             if (m_flags[i] ||
//                 (i > 0 && m_flags[i - 1] && nums.at(i) == nums.at(i - 1))) {
//                 continue;
//             }
//             m_flags[i] = true;
//             path.push_back(nums[i]);
//             dfs(nums, path);
//             path.pop_back();
//             m_flags[i] = false;
//         }
//     }
//     vector<vector<int>> permuteUnique(vector<int> &nums)
//     {
//         m_verPath.clear();
//         m_flags.resize(nums.size(), false);
//         vector<int> path;
//         sort(nums.begin(), nums.end());
//         dfs(nums, path);
//         return m_verPath;
//     }
// private:
//     vector<vector<int>> m_verPath;
//     vector<int> m_flags;
// };

vector<vector<int>> permuteUnique(vector<int> &&nums)
{
    return Solution().permuteUnique(nums);
}

TEST(Solution, leetcode)
{
    vector<vector<int>> vecVecActual;
    vector<vector<int>> vecVecExpected;

    vecVecActual = permuteUnique(vector<int>{2, 1, 1});
    vecVecExpected = vector<vector<int>>{{1, 1, 2}, {1, 2, 1}, {2, 1, 1}};
    EXPECT_TRUE(isEqualWithoutOrder(vecVecActual, vecVecExpected))
        << "  Actual:\n"
        << getString(vecVecActual) << "\n"
        << "Expected:\n"
        << getString(vecVecExpected);

    vecVecActual = permuteUnique(vector<int>{2, 2, 1, 1});
    vecVecExpected =
        vector<vector<int>>{{1, 1, 2, 2}, {1, 2, 1, 2}, {1, 2, 2, 1},
                            {2, 1, 1, 2}, {2, 1, 2, 1}, {2, 2, 1, 1}};
    EXPECT_TRUE(isEqualWithoutOrder(vecVecActual, vecVecExpected))
        << "  Actual:\n"
        << getString(vecVecActual) << "\n"
        << "Expected:\n"
        << getString(vecVecExpected);

    vecVecActual = permuteUnique(vector<int>{2, 1, 1, 1});
    vecVecExpected = vector<vector<int>>{
        {1, 1, 1, 2}, {1, 1, 2, 1}, {1, 2, 1, 1}, {2, 1, 1, 1}};
    EXPECT_TRUE(isEqualWithoutOrder(vecVecActual, vecVecExpected))
        << "  Actual:\n"
        << getString(vecVecActual) << "\n"
        << "Expected:\n"
        << getString(vecVecExpected);
}

int main(int argc, char *argv[])
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
