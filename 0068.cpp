
#include "data_define.h"

class Solution
{
public:
    vector<string> fullJustify(vector<string> &words, int maxWidth)
    {
        std::vector<std::string> vecRet;
        std::string strLine;
        vector<int> vecSpaceId;
        for (int i = 0; i < (int)words.size(); ++i) {
            if (strLine.empty()) {
                strLine.append(words[i]);
            } else {
                if (strLine.size() + words[i].size() + 1 <= maxWidth) {
                    strLine.push_back(' ');
                    vecSpaceId.push_back(strLine.size() - 1);
                    strLine.append(words[i]);
                } else {
                    updateStr(vecSpaceId, maxWidth, strLine);
                    vecRet.push_back(strLine);
                    strLine.clear();
                    vecSpaceId.clear();
                    strLine.append(words[i]);
                }
            }
        }
        int nSpaceDiff = maxWidth - strLine.size();
        strLine.insert(strLine.size(), nSpaceDiff, ' ');
        vecRet.push_back(strLine);
        return vecRet;
    }
private:
    void updateStr(const vector<int> &vecSpaceId, int maxWidth, std::string &strLine)
    {
        int nRemainSpaceCount = maxWidth - strLine.size();
        int nLen = vecSpaceId.size();
        if (nLen == 0) {
            strLine.insert(strLine.size(), nRemainSpaceCount, ' ');
            return;
        }
        vector<int> vecSpaceCount(nLen, 0);
        while (nRemainSpaceCount > 0) {
            for (int j = 0; j < nLen && nRemainSpaceCount > 0; ++j) {
                vecSpaceCount[j]++;
                nRemainSpaceCount--;
            }
        }
        for (int i = nLen - 1; i >= 0; --i) {
            strLine.insert(vecSpaceId[i], vecSpaceCount[i], ' ');
        }
    }
};

TEST(Solution, leetcode)
{
    std::vector<std::string> vecStrInput;
    std::vector<std::string> vecStrOutput;
    std::vector<std::string> vecStrExpected;

    vecStrInput = {"Listen", "to", "many,", "speak", "to", "a", "few."};
    vecStrExpected = {"Listen", "to    ", "many, ", "speak ", "to   a", "few.  "};
    vecStrOutput = Solution().fullJustify(vecStrInput, 6);
    EXPECT_TRUE(vecStrOutput == vecStrExpected)
        << "\ninput:   " << getString(vecStrInput) << "\nouput:   " << getString(vecStrOutput)
        << "\nexpected:" << getString(vecStrExpected);

    vecStrInput = {"What", "must", "be", "acknowledgment", "shall", "be"};
    vecStrExpected = {"What   must   be", "acknowledgment  ", "shall be        "};
    vecStrOutput = Solution().fullJustify(vecStrInput, 16);
    EXPECT_TRUE(vecStrOutput == vecStrExpected)
        << "\ninput:   " << getString(vecStrInput) << "\nouput:   " << getString(vecStrOutput)
        << "\nexpected:" << getString(vecStrExpected);

    vecStrInput = {"Science", "is", "what",       "we",   "understand", "well",
                   "enough",  "to", "explain",    "to",   "a",          "computer.",
                   "Art",     "is", "everything", "else", "we",         "do"};
    vecStrExpected = {"Science  is  what we", "understand      well", "enough to explain to",
                      "a  computer.  Art is", "everything  else  we", "do                  "};
    vecStrOutput = Solution().fullJustify(vecStrInput, 20);
    EXPECT_TRUE(vecStrOutput == vecStrExpected)
        << "\ninput:   " << getString(vecStrInput) << "\nouput:   " << getString(vecStrOutput)
        << "\nexpected:" << getString(vecStrExpected);

    vecStrInput = {"This", "is", "an", "example", "of", "text", "justification."};
    vecStrExpected = {"This    is    an", "example  of text", "justification.  "};
    vecStrOutput = Solution().fullJustify(vecStrInput, 16);
    EXPECT_TRUE(vecStrOutput == vecStrExpected)
        << "\ninput:   " << getString(vecStrInput) << "\nouput:   " << getString(vecStrOutput)
        << "\nexpected:" << getString(vecStrExpected);
}

int main(int argc, char *argv[])
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
