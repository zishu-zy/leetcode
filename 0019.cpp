#include <algorithm>
#include <fstream>
#include <iostream>
#include <limits.h>
#include <math.h>
#include <sstream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

void split(const std::string &s, const char delim, std::vector<int> &sv)
{
    sv.clear();
    std::istringstream iss(s);
    std::string temp;
    while (std::getline(iss, temp, delim)) {
        if (temp.empty())
            continue;
        sv.emplace_back(std::move(atoi(temp.c_str())));
    }
    return;
}

std::string readFile(const std::string &file)
{
    std::fstream in(file);
    std::istreambuf_iterator<char> beg(in), end;
    std::string strdata(beg, end);
    in.close();
    return strdata;
}

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        if (head->next == NULL) {
            // 只有一个节点
            return NULL;
        } else if (head->next->next == NULL) {
            // 只有两个节点
            if (n == 1) {
                delete head->next;
                head->next = NULL;
            } else if (n == 2) {
                ListNode *tmp = head->next;
                delete head;
                head = tmp;
            }
            return head;
        }
        // 节点数至少有三个
        ListNode *pNodeP = NULL;
        ListNode *pNode = head;
        ListNode *pNodeN = head->next;
        ListNode *r = head;
        int count = 0;
        while (r != NULL) {
            count++;
            if (count - n > 0) {
                pNodeP = pNode;
                pNode = pNodeN;
                pNodeN = pNodeN->next;
            }
            r = r->next;
        }
        if (pNode == head) {
            head = pNode->next;
            delete pNode;
        } else {
            pNodeP->next = pNodeN;
            delete pNode;
        }
        return head;
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
        int n = stringToInteger(line);

        ListNode *ret = Solution().removeNthFromEnd(head, n);

        string out = listNodeToString(ret);
        cout << out << endl;
    }
    return 0;
}
