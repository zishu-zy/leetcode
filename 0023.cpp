#include <algorithm>
#include <assert.h>
#include <fstream>
#include <iostream>
#include <limits.h>
#include <math.h>
#include <sstream>
#include <stack>
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
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        ListNode *head = NULL;
        ListNode *r = NULL;
        if (l1 == NULL) {
            return l2;
        } 
        if (l2 == NULL) {
            return l1;
        }
        if (l1->val <= l2->val) {
            head = l1;
            r = l1;
            l1 = l1->next;
        } else {
            head = l2;
            r = l2;
            l2 = l2->next;
        }
        while (l1 != NULL && l2 != NULL) {
            if (l1->val <= l2->val) {
                r->next = l1;
                r = l1;
                l1 = l1->next;
            } else {
                r->next = l2;
                r = l2;
                l2 = l2->next;
            }
        }
        if (l1 != NULL) {
            r->next = l1;
        } else if (l2 != NULL) {
            r->next = l2;
        }
        return head;
    }
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        if (lists.empty()) {
            return NULL;
        }
        int len = lists.size();
        int n = 1;
        while (n < len) {
            for (int i = 0; i < len; i += n * 2) {
                if(i+n >= len)
                    continue;
                
                // cout << len << " " <<i << " " << i+n << endl;
                lists[i] = mergeTwoLists(lists[i], lists[i + n]);
            }
            n *= 2;
        }
        return lists[0];

        // if (lists.empty()) {
        //     return NULL;
        // }
        // ListNode *head = NULL;
        // ListNode *r = NULL;
        // int minNum = INT_MAX;
        // int minid = 0;          // 所有链表中头最小的索引
        // int len = lists.size(); // 链表的个数
        // // 主要是为了找到第一个
        // bool flag = false;
        // for (int i = 0; i < len; ++i) {
        //     if (lists[i] != NULL) {
        //         flag = true;
        //         if (lists[i]->val < minNum) {
        //             minNum = lists[i]->val;
        //             minid = i;
        //         }
        //     }
        // }
        // if (!flag) {
        //     return NULL;
        // }
        // vector<int> sortArr(len);
        // head = lists[minid];
        // r = head;
        // lists[minid] = lists[minid]->next;
        // while (flag) {
        //     flag = false;
        //     minNum = INT_MAX;
        //     for (int i = 0; i < len; ++i) {
        //         if (lists[i] != NULL) {
        //             flag = true;
        //             if (lists[i]->val < minNum) {
        //                 minNum = lists[i]->val;
        //                 minid = i;
        //             }
        //         }
        //     }
        //     if (flag) {
        //         r->next = lists[minid];
        //         r = lists[minid];
        //         lists[minid] = lists[minid]->next;
        //     }
        // }
        // return head;
    }
};

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
        ListNode *l1 = stringToListNode(line);
        getline(cin, line);
        ListNode *l2 = stringToListNode(line);
        vector<ListNode *> arr;
        arr.push_back(l1);
        arr.push_back(l2);

        ListNode *ret = Solution().mergeKLists(arr);

        string out = listNodeToString(ret);
        cout << out << endl;
    }
    return 0;
}
