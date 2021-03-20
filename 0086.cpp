
#include "data_define.h"
class Solution
{
public:
    ListNode *partition(ListNode *head, int x)
    {
        if (head == nullptr) {
            return head;
        }

        ListNode *listHead_1 = new ListNode(0);
        ListNode *listTail_1 = listHead_1;

        ListNode *listHead_2 = new ListNode(0);
        ListNode *listTail_2 = listHead_2;

        ListNode *nodeTmp = head;

        while (nodeTmp != nullptr) {
            // std::cout << nodeTmp->val << std::endl;
            if (nodeTmp->val < x) {
                listTail_1->next = nodeTmp;
                listTail_1 = nodeTmp;
            } else {
                listTail_2->next = nodeTmp;
                listTail_2 = nodeTmp;
            }
            ListNode *nodeTmpNext = nodeTmp->next;
            nodeTmp->next = nullptr;
            nodeTmp = nodeTmpNext;
            // print(listHead_1);
            // print(listHead_2);
        }

        listTail_1->next = listHead_2->next;
        delete listHead_2;
        nodeTmp = listHead_1->next;
        delete listHead_1;
        return nodeTmp;
    }
};

TEST(Solution, leetcode)
{
    ListNode *input;
    ListNode *output;
    ListNode *expected;

    input = initListNode({1, 2, 3});
    output = initListNode({1, 2, 3});
    output = Solution().partition(output, 4);
    expected = initListNode({1, 2, 3});
    EXPECT_TRUE(isEqualListNode(output, expected))
        << "\ninput:   " << getString(input) << "\nouput:   " << getString(output)
        << "\nexpected:" << getString(expected);

    input = initListNode({2});
    output = initListNode({2});
    output = Solution().partition(output, 1);
    expected = initListNode({2});
    EXPECT_TRUE(isEqualListNode(output, expected))
        << "\ninput:   " << getString(input) << "\nouput:   " << getString(output)
        << "\nexpected:" << getString(expected);

    input = initListNode({2});
    output = initListNode({2});
    output = Solution().partition(output, 3);
    expected = initListNode({2});
    EXPECT_TRUE(isEqualListNode(output, expected))
        << "\ninput:   " << getString(input) << "\nouput:   " << getString(output)
        << "\nexpected:" << getString(expected);

    input = initListNode({2, 1, -1, 3, 1, 5, 4});
    output = initListNode({2, 1, -1, 3, 1, 5, 4});
    output = Solution().partition(output, 2);
    expected = initListNode({1, -1, 1, 2, 3, 5, 4});
    EXPECT_TRUE(isEqualListNode(output, expected))
        << "\ninput:   " << getString(input) << "\nouput:   " << getString(output)
        << "\nexpected:" << getString(expected);

    input = initListNode({2, 1});
    output = initListNode({2, 1});
    output = Solution().partition(output, 2);
    expected = initListNode({1, 2});
    EXPECT_TRUE(isEqualListNode(output, expected))
        << "\ninput:   " << getString(input) << "\nouput:   " << getString(output)
        << "\nexpected:" << getString(expected);

    input = initListNode({1, 4, 3, 2, 5, 2});
    output = initListNode({1, 4, 3, 2, 5, 2});
    output = Solution().partition(output, 3);
    expected = initListNode({1, 2, 2, 4, 3, 5});
    EXPECT_TRUE(isEqualListNode(output, expected))
        << "\ninput:   " << getString(input) << "\nouput:   " << getString(output)
        << "\nexpected:" << getString(expected);
}

int main(int argc, char *argv[])
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
