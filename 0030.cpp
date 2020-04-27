
/*
 * 通过遍历字符串s，对每个子串遍历数组word，判断是否可以包含所有元素，
 * 如果可以包含则当前的id是符合，如果不能，id++，但是在有些情况下会超时，
 * 这时引入了vecFlag进行预判断，如果后面存在和前面已经比较过的不符合的子串相同，
 * 则直接设置为false，节省时间
 */

#include "data_define.h"

class Solution
{
public:
    vector<int> findSubstring(string s, vector<string> &words)
    {
        std::ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        if (words.size() == 0)
            return {};
        int n = words.size();
        int len = words[0].size();
        if (s.size() < n * len)
            return {};
        unordered_map<string, int> m;
        for (int i = 0; i < n; ++i)
            ++m[words[i]];

        vector<int> res;
        for (int i = 0; i < len; ++i) {
            int start = i;
            int pos = start;
            int cnt = 0;
            unordered_map<string, int> store;
            while (start + n * len <= s.size()) {
                while (cnt < n && m.find(s.substr(pos, len)) != m.end()) {
                    ++cnt;
                    ++store[s.substr(pos, len)];
                    pos += len;
                }
                if (cnt == n) {
                    if (store == m)
                        res.push_back(pos - n * len);
                    --cnt;
                    --store[s.substr(start, len)];
                    start += len;
                } else {
                    cnt = 0;
                    store.clear();
                    start = pos + len;
                    pos = start;
                }
            }
        }

        return res;
    }
};

// class Solution
// {
// public:
//     vector<int> findSubstring(string s, vector<string> &words)
//     {
//         vector<int> vecRet;
//         int nWordCount = words.size();
//         if (nWordCount == 0) {
//             return vecRet;
//         }
//         int nWordLen = words.at(0).size();
//         int nStrLen = s.size();
//         if (nStrLen < nWordLen * nWordCount) {
//             return vecRet;
//         }
//         vector<bool> vecFlag(s.size(), true);
//         for (int nId = 0; nId < nStrLen; ++nId) {
//             if (!vecFlag[nId]) {
//                 continue;
//             }
//             int nWordCountTmp = nWordCount;
//             // vecStrTmp = words;
//             for (int i = nId; i < nStrLen;) {
//                 string strTmp = s.substr(i, nWordLen);
//                 bool bFound = false;
//                 for (int j = 0; j < nWordCountTmp; ++j) {
//                     // std::cout << j << " ";
//                     if (words.at(j) == strTmp) {
//                         swap(words[j], words[nWordCountTmp - 1]);
//                         nWordCountTmp -= 1;
//                         bFound = true;
//                         break;
//                     }
//                 }
//                 if (bFound) {
//                     if (nWordCountTmp == 0) {
//                         vecRet.push_back(nId);
//                         break;
//                     }
//                     i += nWordLen;
//                 } else {
//                     string strTmp = s.substr(
//                         nId, nWordLen * (nWordCount - nWordCountTmp + 1));
//                     if (!strTmp.empty()) {
//                         int nTmp = s.find(strTmp, nId + 1);
//                         while (nTmp != string::npos) {
//                             // std::cout << nTmp << std::endl;
//                             vecFlag[nTmp] = false;
//                             nTmp = s.find(strTmp, nTmp + 1);
//                         }
//                     }
//                     break;
//                 }
//                 // std::cout << std::endl;
//             }
//         }
//         return vecRet;
//     }
// };

int main(void)
{
    Solution s;
    string strStr = "wordgoodgoodgoodbestword";
    vector<string> vecWords = {"word", "good", "best", "good"};
    vector<int> vecRet = s.findSubstring(strStr, vecWords);
    print(vecRet);
    return 0;
}
