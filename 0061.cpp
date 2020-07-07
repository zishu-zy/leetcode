
#include "data_define.h"

// 最快的
class Solution
{
public:
    ListNode *rotateRight(ListNode *head, int k)
    {
        if (!head || !head->next || k == 0)
            return head;
        int len = 1;
        ListNode *p = head;
        while (p->next) {
            ++len;
            p = p->next;
        }
        k = len - k % len;
        if (k == 0)
            return head;
        p->next = head;
        while (k--)
            p = p->next;
        head = p->next;
        p->next = nullptr;
        return head;
    }
};

class Solution2
{
public:
    ListNode *rotateRight(ListNode *head, int k)
    {
        if (k == 0 || head == NULL) {
            return head;
        }
        ListNode *headtmp = NULL;
        ListNode *nodeTmp = head;
        int nListLen = 0;
        while (nodeTmp != NULL) {
            nListLen++;
            nodeTmp = nodeTmp->next;
        }
        if (k % nListLen == 0) {
            return head;
        }
        nodeTmp = head;
        int nTmp = nListLen - k % nListLen;
        int i = 0;
        ListNode *headPre = NULL;
        while (nodeTmp != NULL) {
            if (i == nTmp) {
                headtmp = nodeTmp;
                headPre->next = NULL;
                while (nodeTmp->next != NULL) {
                    nodeTmp = nodeTmp->next;
                }
                nodeTmp->next = head;
                break;
            }
            i++;
            headPre = nodeTmp;
            nodeTmp = nodeTmp->next;
        }
        return headtmp;
    }
};

TEST(Solution, leetcode)
{
    ListNode *listInput;
    ListNode *listActual;
    ListNode *listExpected;
    listInput = initListNode(vector<int>{1, 2, 3, 4, 5});
    listExpected = initListNode(vector<int>{4, 5, 1, 2, 3});
    listActual = Solution().rotateRight(listInput, 2);
    EXPECT_TRUE(isEqualListNode(listActual, listExpected)) << "  Actual:\n"
                                                           << getString(listActual) << "\n"
                                                           << "Expected:\n"
                                                           << getString(listExpected);

    listInput = initListNode(vector<int>{1, 2, 3, 4, 5});
    listExpected = initListNode(vector<int>{5, 1, 2, 3, 4});
    listActual = Solution().rotateRight(listInput, 1);
    EXPECT_TRUE(isEqualListNode(listActual, listExpected)) << "  Actual:\n"
                                                           << getString(listActual) << "\n"
                                                           << "Expected:\n"
                                                           << getString(listExpected);

    listInput = initListNode(vector<int>{1, 2, 3, 4, 5});
    listExpected = initListNode(vector<int>{5, 1, 2, 3, 4});
    listActual = Solution().rotateRight(listInput, 6);
    EXPECT_TRUE(isEqualListNode(listActual, listExpected)) << "  Actual:\n"
                                                           << getString(listActual) << "\n"
                                                           << "Expected:\n"
                                                           << getString(listExpected);
}

int main(int argc, char *argv[])
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
