
#include "data_define.h"

// 最快的 - 质数牛逼，数学很重要，当时就是这个hash想不出来
class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        int a[26] = {2,  3,  5,  7,  11, 13, 17, 19, 23, 29, 31, 37, 41,
                     43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101};
        unordered_map<double, vector<string>> M;
        for (string &s : strs) {
            double key = 1;
            for (char &c : s)
                key *= a[c - 'a'];
            M[key].push_back(s);
        }
        vector<vector<string>> ans;
        for (auto &p : M)
            ans.push_back(p.second);
        return ans;
    }
};

// class Solution
// {
// public:
//     vector<vector<string>> groupAnagrams(vector<string> &strs)
//     {
//         map<vector<int>, vector<string>> mapVecCount;
//         int nLen = strs.size();
//         for (int i = 0; i < nLen; ++i) {
//             vector<int> vecAbc(26, 0);
//             for (int j = 0; j < (int)strs.at(i).size(); ++j) {
//                 vecAbc[strs.at(i).at(j) - 'a']++;
//             }
//             mapVecCount[vecAbc].push_back(strs.at(i));
//         }
//         vector<vector<string>> vecVecRet;
//         for (map<vector<int>, vector<string>>::iterator mapIt =
//                  mapVecCount.begin();
//              mapIt != mapVecCount.end(); ++mapIt) {
//             vecVecRet.push_back(mapIt->second);
//         }
//         return vecVecRet;
//     }
// };

vector<vector<string>> groupAnagrams(vector<string> &&strs)
{
    return Solution().groupAnagrams(strs);
}

TEST(Solution, leetcode)
{
    vector<vector<string>> vecVecActual;
    vector<vector<string>> vecVecExpected;

    vecVecActual = groupAnagrams(vector<string>{
        "eat", "tea", "tan", "ate", "nat", "bat", "ab", "abb", "aab"});
    vecVecExpected =
        vector<vector<string>>{{"ab"},  {"abb"},        {"aab"},
                               {"bat"}, {"nat", "tan"}, {"ate", "eat", "tea"}};
    EXPECT_TRUE(isEqualWithoutOrder_2(vecVecActual, vecVecExpected))
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
