
#include "data_define.h"

class Solution
{
public:
    ListNode *deleteDuplicates(ListNode *head)
    {
        if (head == NULL) {
            return NULL;
        }
        ListNode *pPre = head;
        ListNode *pCur = head->next;

        while (pCur != NULL) {
            if (pCur->val == pPre->val) {
                pPre->next = pCur->next;
            } else {
                pPre = pCur;
            }
            pCur = pCur->next;
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
    expected = initListNode({1, 2, 3, 4, 5});
    EXPECT_TRUE(isEqualListNode(output, expected))
        << "\ninput:   " << getString(input) << "\nouput:   " << getString(output)
        << "\nexpected:" << getString(expected);
}

int main(int argc, char *argv[])
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
