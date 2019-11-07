/*
 * ==============================================================
 *
 *       FileName: 0002.cpp
 *    Description:
 *
 *         Author: zhaiyu, zishuzy@gmail.com
 *        Created: 2018-11-24 20:49:07
 *  Last Modified: 2018-11-25 11:08:03
 *
 *  Copyright (C) 2018 zhaiyu. All rights reserved.
 *
 * ==============================================================
 */
#include <algorithm>
#include <iostream>
#include <sstream>
#include <unordered_map>
#include <vector>
#include <string>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
#if 0
        ListNode *head = NULL;
        ListNode *tmpNode = NULL;
        ListNode *cuNode = NULL;
        int tmpVal;
        int cf = 0;
        while (l1 != NULL && l2 != NULL) {
            tmpVal = l1->val + l2->val + cf;
            if (tmpVal > 9) {
                cf = 1;
                tmpVal -= 10;
            } else {
                cf = 0;
            }
            tmpNode = new ListNode(0);
            tmpNode->val = tmpVal;
            if (head == NULL) {
                head = tmpNode;
                cuNode = tmpNode;
            } else {
                cuNode->next = tmpNode;
                cuNode = tmpNode;
            }
            l1 = l1->next;
            l2 = l2->next;
        }
        while (l1 != NULL) {
            tmpNode = new ListNode(0);
            tmpVal = l1->val + cf;
            if (tmpVal > 9) {
                cf = 1;
                tmpVal -= 10;
            } else {
                cf = 0;
            }
            tmpNode->val = tmpVal;
            if (head == NULL) {
                head = tmpNode;
                cuNode = tmpNode;
            } else {
                cuNode->next = tmpNode;
                cuNode = tmpNode;
            }
            l1 = l1->next;
        }
        while (l2 != NULL) {
            tmpNode = new ListNode(0);
            tmpVal = l2->val + cf;
            if (tmpVal > 9) {
                cf = 1;
                tmpVal -= 10;
            } else {
                cf = 0;
            }
            tmpNode->val = tmpVal;
            if (head == NULL) {
                head = tmpNode;
                cuNode = tmpNode;
            } else {
                cuNode->next = tmpNode;
                cuNode = tmpNode;
            }
            l2 = l2->next;
        }
        if (cf == 1) {
            tmpNode = new ListNode(0);
            tmpNode->val = 1;
            if (head == NULL) {
                head = tmpNode;
                cuNode = tmpNode;
            } else {
                cuNode->next = tmpNode;
                cuNode = tmpNode;
            }
        }
        return head;
#endif
        ListNode *res = new ListNode(-1);
        ListNode *cur = res;
        int carry = 0;
        while (l1 || l2) {
            int n1 = l1 ? l1->val : 0;
            int n2 = l2 ? l2->val : 0;
            int sum = n1 + n2 + carry;
            carry = sum / 10;
            cur->next = new ListNode(sum % 10);
            cur = cur->next;
            if (l1)
                l1 = l1->next;
            if (l2)
                l2 = l2->next;
        }
        if (carry == 1)
            cur->next = new ListNode(1);
        return res->next;
    }
};

void trimLeftTrailingSpaces(string &input)
{
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) { return !isspace(ch); }));
}

void trimRightTrailingSpaces(string &input)
{
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) { return !isspace(ch); }).base(), input.end());
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

        ListNode *ret = Solution().addTwoNumbers(l1, l2);

        string out = listNodeToString(ret);
        cout << out << endl;
    }
    return 0;
}
