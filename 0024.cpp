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
    ListNode *swapPairs(ListNode *head)
    {
        // 空链表
        if (head == NULL) {
            return NULL;
        }
        // 只有一个元素
        if (head->next == NULL) {
            return head;
        }
        ListNode *result = head->next;
        ListNode *tmpListS = head;
        ListNode *tmpListEnd = new ListNode(0);
        // ListNode *tmpListC;
        bool flag = true;
        head = head->next;
        while (head != NULL) {
            if (flag) {
                tmpListS->next = head->next;
                head->next = tmpListS;
                tmpListEnd->next = head;
                tmpListEnd = tmpListS;
                head = tmpListS->next;
            } else {
                tmpListS = head;
                head = head->next;
            }
            flag = !flag;
        }
        return result;
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
        ListNode *head = stringToListNode(line);

        ListNode *ret = Solution().swapPairs(head);

        string out = listNodeToString(ret);
        cout << out << endl;
    }
    return 0;
}
