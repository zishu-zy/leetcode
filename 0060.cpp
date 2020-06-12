
#include "data_define.h"

class Solution
{
public:
    inline int factorial(int num)
    {
        if (num == 0) {
            return 1;
        } else {
            return num * factorial(num - 1);
        }
    }

    void dfs(vector<int> &nums, vector<int> &path, int n_used_count)
    {
        int nPathSize = path.size();
        int nNumsSize = nums.size();
        if (nPathSize == nNumsSize) {
            m_nCount++;
            if (m_nCount == m_nK) {
                for (auto i : path) {
                    m_strRet.push_back('0' + i);
                }
            }
            return;
        }
        for (int i = 0; i < nNumsSize; ++i) {
            if (m_nCount >= m_nK) {
                return;
            } else if (m_vecFlags[i]) {
                continue;
            }
            m_vecFlags[i] = true;
            n_used_count++;
            path.push_back(nums[i]);
            int nTmp = factorial(nNumsSize - n_used_count);
            if (m_nCount + nTmp >= m_nK) {
                dfs(nums, path, n_used_count);
            } else {
                m_nCount += nTmp;
            }
            path.pop_back();
            n_used_count--;
            m_vecFlags[i] = false;
        }
    }

    string getPermutation(int n, int k)
    {
        m_nK = k;
        vector<int> vecTmp(n, 0);
        for (int i = 0; i < n; ++i) {
            vecTmp[i] = i + 1;
        }
        m_nCount = 0;
        m_vecFlags.resize(n, false);
        vector<int> path;
        dfs(vecTmp, path, 0);
        return m_strRet;
    }

private:
    int m_nK;
    int m_nCount;
    string m_strRet;
    vector<bool> m_vecFlags;
};

TEST(Solution, leetcode)
{
    EXPECT_EQ(Solution().getPermutation(3, 3), "213");
    EXPECT_EQ(Solution().getPermutation(4, 9), "2314");
    EXPECT_EQ(Solution().getPermutation(9, 353955), "972561438");
}

int main(int argc, char *argv[])
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
