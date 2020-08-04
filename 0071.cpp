
#include "data_define.h"

class Solution
{
public:
    string simplifyPath(string path)
    {
        int nLen = path.size();
        int nStartId = -1;
        std::stack<string> stackTmp;
        std::string strRet;
        std::string strTmp;
        for (int i = 0; i < nLen; ++i) {
            if (path[i] == '/') {
                if (nStartId == -1) {
                    nStartId = i;
                } else {
                    strTmp = path.substr(nStartId + 1, i - nStartId - 1);
                    nStartId = i;
                    if (strTmp.empty() || strTmp == ".") {
                        continue;
                    } else if (strTmp == "..") {
                        if (!stackTmp.empty()) {
                            stackTmp.pop();
                        }
                    } else {
                        stackTmp.push(strTmp);
                    }
                }
            }
        }
        strTmp = path.substr(nStartId + 1, nLen - nStartId - 1);
        if (!strTmp.empty()) {
            if (strTmp == "..") {
                if (!stackTmp.empty()) {
                    stackTmp.pop();
                }
            } else if (strTmp != ".") {
                stackTmp.push(strTmp);
            }
        }
        while (!stackTmp.empty()) {
            strRet.insert(0, stackTmp.top().c_str());
            strRet.insert(0, "/");
            stackTmp.pop();
        }
        return strRet.empty() ? "/" : strRet;
    }
};

TEST(Solution, leetcode)
{
    std::string strInput;
    std::string strOutput;
    std::string strExpected;

    strInput = "/..";
    strOutput = Solution().simplifyPath(strInput);
    strExpected = "/";
    EXPECT_TRUE(strOutput == strExpected)
        << "\ninput:   " << strInput << "\nouput:   " << strOutput << "\nexpected:" << strExpected;

    strInput = "/.";
    strOutput = Solution().simplifyPath(strInput);
    strExpected = "/";
    EXPECT_TRUE(strOutput == strExpected)
        << "\ninput:   " << strInput << "\nouput:   " << strOutput << "\nexpected:" << strExpected;

    strInput = "/home/";
    strOutput = Solution().simplifyPath(strInput);
    strExpected = "/home";
    EXPECT_TRUE(strOutput == strExpected)
        << "\ninput:   " << strInput << "\nouput:   " << strOutput << "\nexpected:" << strExpected;

    strInput = "/../";
    strOutput = Solution().simplifyPath(strInput);
    strExpected = "/";
    EXPECT_TRUE(strOutput == strExpected)
        << "\ninput:   " << strInput << "\nouput:   " << strOutput << "\nexpected:" << strExpected;

    strInput = "/home//foo/";
    strOutput = Solution().simplifyPath(strInput);
    strExpected = "/home/foo";
    EXPECT_TRUE(strOutput == strExpected)
        << "\ninput:   " << strInput << "\nouput:   " << strOutput << "\nexpected:" << strExpected;

    strInput = "/a/./b/../../c/";
    strOutput = Solution().simplifyPath(strInput);
    strExpected = "/c";
    EXPECT_TRUE(strOutput == strExpected)
        << "\ninput:   " << strInput << "\nouput:   " << strOutput << "\nexpected:" << strExpected;

    strInput = "/a/../../b/../c//.//";
    strOutput = Solution().simplifyPath(strInput);
    strExpected = "/c";
    EXPECT_TRUE(strOutput == strExpected)
        << "\ninput:   " << strInput << "\nouput:   " << strOutput << "\nexpected:" << strExpected;

    strInput = "/a//b////c/d//././/..";
    strOutput = Solution().simplifyPath(strInput);
    strExpected = "/a/b/c";
    EXPECT_TRUE(strOutput == strExpected)
        << "\ninput:   " << strInput << "\nouput:   " << strOutput << "\nexpected:" << strExpected;

    strInput = "/a//b////c/d//././/e";
    strOutput = Solution().simplifyPath(strInput);
    strExpected = "/a/b/c/d/e";
    EXPECT_TRUE(strOutput == strExpected)
        << "\ninput:   " << strInput << "\nouput:   " << strOutput << "\nexpected:" << strExpected;
}

int main(int argc, char *argv[])
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
