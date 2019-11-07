#include <algorithm>
#include <assert.h>
#include <fstream>
#include <iostream>
#include <limits.h>
#include <math.h>
#include <sstream>
#include <stack>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
    // 巧妙，返回的表尾，而表尾是指向表头的！！！
    ListNode *reverse(ListNode *begin, ListNode *end)
    {
        ListNode *p, *t;
        for (p = begin, begin = end; p != end; p = t) { //直到p和t相遇为止
            t = p->next;                                // p向后移动
            p->next = begin;                            // begin向前移动
            begin = p;
        }
        return begin; // tail link to end
    }

public:
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        if (!head || k < 2)
            return head;
        ListNode H(-1), *tail, *end;
        for (H.next = head, tail = head = &H; (end = head = head->next);) {
            for (int i = 0; ++i < k && end; end = end->next)
                ; //从head开始，循环找到终止位置
            if (end == NULL)
                break;                             // not enough k nodes
            tail->next = reverse(head, end->next); // tail 等于H，相当于是头部
            tail = head;                           // tail->next auto link to
            // next，原来的head已经到尾巴，将tai头部更新到下一个位置
        }
        return H.next;
    }
};

// class Solution
// {
// public:
//     ListNode *reverseKGroup(ListNode *head, int k)
//     {
//         if (head == NULL) {
//             return NULL;
//         }
//         if (head->next == NULL) {
//             return head;
//         }
//         ListNode *res;
//         int count = 0;
//         ListNode *lastt = NULL;
//         ListNode *r = head;
//         tuple<ListNode *, ListNode *> ht;
//         while (r != NULL) {
//             if (count == 0) {
//                 head = r;
//             }
//             count++;
//             r = r->next;
//             if (count == k) {
//                 count = 0;
//                 ht = inversion(head, k);
//                 if (lastt == NULL) {
//                     res = get<0>(ht);
//                     lastt = get<1>(ht);
//                 } else {
//                     lastt->next = get<0>(ht);
//                     lastt = get<1>(ht);
//                 }
//             }
//         }
//         if (count != 0) {
//             if (lastt == NULL) {
//                 res = head;
//             } else {
//                 lastt->next = head;
//             }
//         }
//         return res;
//     }
//     tuple<ListNode *, ListNode *> inversion(ListNode *head, int k)
//     {
//         // 一个节点
//         if (k == 1) {
//             return tuple<ListNode *, ListNode *>{head, head};
//         }
//         // 两个节点
//         if (k == 2) {
//             ListNode *c = head->next;
//             c = head->next;
//             c->next = head;
//             head->next = NULL;
//             return tuple<ListNode *, ListNode *>{c, c->next};
//         }
//         // 三个及以上
//         ListNode *p = head;
//         ListNode *c = head->next;
//         ListNode *n = head->next->next;
//         p->next = NULL;
//         ListNode *tail = p; // 表尾
//         for (int i = 2; i < k; ++i) {
//             c->next = p;
//             p = c;
//             c = n;
//             n = n->next;
//         }
//         c->next = p;
//         return tuple<ListNode *, ListNode *>{c, tail};
//     }
// };

void trimLeftTrailingSpaces(string &input)
{
    input.erase(input.begin(), find_if(input.begin(), input.end(),
                                       [](int ch) { return !isspace(ch); }));
}

void trimRightTrailingSpaces(string &input)
{
    input.erase(find_if(input.rbegin(), input.rend(),
                        [](int ch) { return !isspace(ch); })
                    .base(),
                input.end());
}

vector<int> stringToIntegerVector(string input)
{
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(stoi(item));
    }
    return output;
}

ListNode *stringToListNode(string input)
{
    // Generate list from the input
    vector<int> list = stringToIntegerVector(input);

    // Now convert that list into linked list
    ListNode *dummyRoot = new ListNode(0);
    ListNode *ptr = dummyRoot;
    for (int item : list) {
        ptr->next = new ListNode(item);
        ptr = ptr->next;
    }
    ptr = dummyRoot->next;
    delete dummyRoot;
    return ptr;
}

int stringToInteger(string input)
{
    return stoi(input);
}

string listNodeToString(ListNode *node)
{
    if (node == nullptr) {
        return "[]";
    }

    string result;
    while (node) {
        result += to_string(node->val) + ", ";
        node = node->next;
    }
    return "[" + result.substr(0, result.length() - 2) + "]";
}

int main()
{
    string line;
    while (getline(cin, line)) {
        ListNode *head = stringToListNode(line);
        getline(cin, line);
        int k = stringToInteger(line);

        // ListNode *ret = Solution().reverseKGroup(head, k);
        ListNode *ret = Solution().reverseKGroup(head, k);

        string out = listNodeToString(ret);
        cout << out << endl;
    }
    return 0;
}
