
#include "data_define.h"

// 简洁
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans=vector<vector<int>>(n, vector<int>(n) );
        int k=(n+1)/2,num=1;
        for(int i=0;i<k;i++){
            int l=i,r=i;
            while(r<=n-1-i)ans[l][r++]=num++;
            l++;r--;
            while(l<=n-1-i) ans[l++][r]=num++;
            r--;l--;
            while(r>=i) ans[l][r--]=num++;
            l--;r++;
            while(l>i) ans[l--][r]=num++;
        }
        return ans;
    }
};

class Solution2
{
public:
    vector<vector<int>> generateMatrix(int n)
    {
        vector<vector<int>> vecVecRet(n, vector<int>(n, -1));
        int i = 0;
        int j = 0;
        int nFlag = 0;
        int nNumCount = 1;
        while (nNumCount <= n * n) {
            // std::cout << i << " " << j << std::endl;
            vecVecRet[i][j] = nNumCount;
            nNumCount++;
            switch (nFlag) {
            case 0:
                ++j;
                if (j >= n) {
                    nFlag = 1;
                    j = n - 1;
                    ++i;
                } else if (vecVecRet[i][j] != -1) {
                    nFlag = 1;
                    --j;
                    ++i;
                }
                break;
            case 1:
                ++i;
                if (i >= n) {
                    nFlag = 2;
                    i = n - 1;
                    --j;
                } else if (vecVecRet[i][j] != -1) {
                    nFlag = 2;
                    --i;
                    --j;
                }
                break;
            case 2:
                --j;
                if (j < 0) {
                    nFlag = 3;
                    j = 0;
                    --i;
                } else if (vecVecRet[i][j] != -1) {
                    nFlag = 3;
                    ++j;
                    --i;
                }
                break;
            case 3:
                --i;
                if (i < 0) {
                    nFlag = 0;
                    i = 0;
                    j = 0;
                } else if (vecVecRet[i][j] != -1) {
                    nFlag = 0;
                    ++i;
                    ++j;
                }
                break;
            default:
                break;
            }
        }
        return vecVecRet;
    }
};

vector<vector<int>> generateMatrix(int n)
{
    return Solution().generateMatrix(n);
}

TEST(Solution, leetcode)
{
    vector<vector<int>> vecVecActual;
    vector<vector<int>> vecVecExpected;

    vecVecActual = generateMatrix(3);
    vecVecExpected = vector<vector<int>>{{1, 2, 3}, {8, 9, 4}, {7, 6, 5}};
    EXPECT_TRUE(vecVecActual == vecVecExpected)
        << "  Actual:\n"
        << getString(vecVecActual) << "\n"
        << "Expected:\n"
        << getString(vecVecExpected);

    vecVecActual = generateMatrix(4);
    vecVecExpected = vector<vector<int>>{
        {1, 2, 3, 4}, {12, 13, 14, 5}, {11, 16, 15, 6}, {10, 9, 8, 7}};
    EXPECT_TRUE(vecVecActual == vecVecExpected)
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
