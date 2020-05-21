
#include "data_define.h"

// 最快的 - 确实就是深度优先搜索
class Solution
{
public:
    void dfs(vector<int> &nums, vector<int> &path)
    {
        int path_size = path.size();
        int nums_size = nums.size();
        if (path_size == nums_size) {
            res.push_back(path);
            return;
        }
        for (int i = 0; i < nums_size; i++) {
            if (flags[i]) {
                continue;
            }
            flags[i] = true;
            path.push_back(nums[i]);
            dfs(nums, path);
            path.pop_back();
            flags[i] = false;
        }
    }
    vector<vector<int>> permute(vector<int> &nums)
    {
        res.clear();
        flags.resize(nums.size(), 0);
        vector<int> path;
        dfs(nums, path);
        return res;
    }
private:
    vector<vector<int>> res;
    vector<int> flags;
};

/*
class Solution
{
public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        if (nums.size() == 1) {
            return {{nums.front()}};
        }

        std::cout << "size:" << nums.size() << std::endl;

        vector<vector<int>> vecVecRet;
        for (int i = 0; i < (int)nums.size(); ++i) {
            vector<int> vecTmp(nums);
            vecTmp.erase(vecTmp.begin() + i);
            vector<vector<int>> vecVecTmp;
            vecVecTmp = permute(vecTmp);
            for (int j = 0; j < (int)vecVecTmp.size(); ++j) {
                vecVecTmp[j].push_back(nums.at(i));
                vecVecRet.push_back(vecVecTmp.at(j));
            }
        }
        return vecVecRet;
    }
};
*/

vector<vector<int>> permute(vector<int> &&nums)
{
    return Solution().permute(nums);
}

TEST(Solution, permute)
{
    vector<vector<int>> vecVecActual;
    vector<vector<int>> vecVecExpected;

    // vecVecActual = permute(vector<int>{2, 1});
    // vecVecExpected = vector<vector<int>>{{1, 2}, {2, 1}};
    // EXPECT_TRUE(isEqualWithoutOrder(vecVecActual, vecVecExpected))
    //     << "  Actual:\n"
    //     << getString(vecVecActual) << "\n"
    //     << "Expected:\n"
    //     << getString(vecVecExpected);

    // vecVecActual = permute(vector<int>{1});
    // vecVecExpected = vector<vector<int>>{{1}};
    // EXPECT_TRUE(isEqualWithoutOrder(vecVecActual, vecVecExpected))
    //     << "  Actual:\n"
    //     << getString(vecVecActual) << "\n"
    //     << "Expected:\n"
    //     << getString(vecVecExpected);

    vecVecActual = permute(vector<int>{2, 3, 1});
    vecVecExpected = vector<vector<int>>{{1, 2, 3}, {1, 3, 2}, {2, 1, 3},
                                         {2, 3, 1}, {3, 1, 2}, {3, 2, 1}};
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
