
#include "data_define.h"

// 不需要自己delete，可以建立一个辅助节点，做二次循环。
class Solution
{
public:
    ListNode *deleteDuplicates(ListNode *head)
    {
        ListNode *h = new ListNode;
        h->next = head;
        ListNode *pre = h;
        ListNode *cur = head;
        ListNode *dup = NULL;
        while (cur != NULL) {
            dup = cur->next;
            while (dup != NULL && dup->val == cur->val) {
                dup = dup->next;
            }
            if (cur->next != dup) {
                pre->next = dup;
                cur = dup;
            } else {
                pre = cur;
                cur = dup;
            }
        }
        return h->next;
    }
};

class Solution_self
{
public:
    ListNode *deleteDuplicates(ListNode *head)
    {
        if (head == NULL) {
            return head;
        }
        if (head->next == NULL) {
            return head;
        }
        ListNode *pPrePre = head;
        ListNode *pPre = head;
        ListNode *pCur = head->next;

        bool bDelFlag = false;
        while (pCur != NULL) {
            if (pCur->val == pPre->val) {
                bDelFlag = true;
                pPre->next = pCur->next;
                delete (pCur);
                pCur = pPre->next;
            } else {
                if (bDelFlag) {
                    if (pPrePre == pPre) {
                        pPrePre = pCur;
                    } else {
                        pPrePre->next = pCur;
                    }
                    if (head == pPre) {
                        head = pCur;
                    }
                    delete (pPre);
                    pPre = pCur;
                    pCur = pCur->next;
                } else {
                    pPrePre = pPre;
                    pPre = pCur;
                    pCur = pCur->next;
                }
                bDelFlag = false;
            }
        }
        if (bDelFlag) {
            pPrePre->next = NULL;
            if (pPrePre == pPre) {
                head = NULL;
            }
            delete (pPre);
        }
        return head;
    }
};

TEST(Solution, leetcode)
{
    ListNode *input;
    ListNode *output;
    ListNode *expected;

    input = initListNode({1, 2, 3, 3, 4, 4, 5});
    output = initListNode({1, 2, 3, 3, 4, 4, 5});
    output = Solution().deleteDuplicates(output);
    expected = initListNode({1, 2, 5});
    EXPECT_TRUE(isEqualListNode(output, expected))
        << "\ninput:   " << getString(input) << "\nouput:   " << getString(output)
        << "\nexpected:" << getString(expected);

    input = initListNode({1, 1, 3});
    output = initListNode({1, 1, 3});
    output = Solution().deleteDuplicates(output);
    expected = initListNode({3});
    EXPECT_TRUE(isEqualListNode(output, expected))
        << "\ninput:   " << getString(input) << "\nouput:   " << getString(output)
        << "\nexpected:" << getString(expected);

    input = initListNode({1, 1, 1, 1, 1, 1});
    output = initListNode({1, 1, 1, 1, 1, 1});
    output = Solution().deleteDuplicates(output);
    expected = initListNode({});
    EXPECT_TRUE(isEqualListNode(output, expected))
        << "\ninput:   " << getString(input) << "\nouput:   " << getString(output)
        << "\nexpected:" << getString(expected);

    input = initListNode({1, 1});
    output = initListNode({1, 1});
    output = Solution().deleteDuplicates(output);
    expected = initListNode({});
    EXPECT_TRUE(isEqualListNode(output, expected))
        << "\ninput:   " << getString(input) << "\nouput:   " << getString(output)
        << "\nexpected:" << getString(expected);

    input = initListNode({1, 2});
    output = initListNode({1, 2});
    output = Solution().deleteDuplicates(output);
    expected = initListNode({1, 2});
    EXPECT_TRUE(isEqualListNode(output, expected))
        << "\ninput:   " << getString(input) << "\nouput:   " << getString(output)
        << "\nexpected:" << getString(expected);

    input = initListNode({1});
    output = initListNode({1});
    output = Solution().deleteDuplicates(output);
    expected = initListNode({1});
    EXPECT_TRUE(isEqualListNode(output, expected))
        << "\ninput:   " << getString(input) << "\nouput:   " << getString(output)
        << "\nexpected:" << getString(expected);

    input = initListNode({1, 1, 1, 2, 3});
    output = initListNode({1, 1, 1, 2, 3});
    output = Solution().deleteDuplicates(output);
    expected = initListNode({2, 3});
    EXPECT_TRUE(isEqualListNode(output, expected))
        << "\ninput:   " << getString(input) << "\nouput:   " << getString(output)
        << "\nexpected:" << getString(expected);
}

int main(int argc, char *argv[])
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
