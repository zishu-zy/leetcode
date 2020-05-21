#ifndef DATA_DEFINE_H_
#define DATA_DEFINE_H_

#include <assert.h>
#include <limits.h>
#include <math.h>
#include <algorithm>
#include <cassert>
#include <fstream>
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <gmock/gmock.h>
#include <gtest/gtest.h>

using namespace std;

template <typename T>
void print(const T &t)
{
    std::cout << t << std::endl;
}

template <typename T>
void print(const vector<T> &t)
{
    for (auto it = t.begin(); it != t.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

template <typename T>
void print(const vector<vector<T>> &t)
{
    for (auto it = t.begin(); it != t.end(); ++it) {
        print(*it);
    }
}

template <typename T>
std::string getString(const T &t)
{
    return std::to_string(t);
}

template <typename T>
std::string getString(const vector<T> &t)
{
    std::string strRet;
    for (auto it = t.begin(); it != t.end(); ++it) {
        if (strRet.empty()) {
            strRet.append("[");
            strRet.append(std::to_string(*it));
        } else {
            strRet.append(",");
            strRet.append(std::to_string(*it));
        }
    }
    strRet.append("]");
    return strRet;
}

template <typename T>
std::string getString(const vector<vector<T>> &t)
{
    std::string strRet;
    for (auto it = t.begin(); it != t.end(); ++it) {
        if (strRet.empty()) {
            strRet.append("[\n  ");
            strRet.append(getString(*it));
        } else {
            strRet.append(",\n  ");
            strRet.append(getString(*it));
        }
    }
    strRet.append("\n]");
    return strRet;
}

template <typename T>
bool isEqualWithoutOrder(const vector<T> &t1, const vector<T> &t2)
{
    if (t1.size() != t2.size())
        return false;
    unordered_set<T> setTmp;
    for (int i = 0; i < (int)t1.size(); ++i) {
        setTmp.insert(t1.at(i));
    }
    bool bRet = true;
    for (int i = 0; i < (int)t2.size(); ++i) {
        if (setTmp.find(t2.at(i)) == setTmp.end()) {
            bRet = false;
            break;
        }
    }
    return bRet;
}

template <typename T>
bool isEqualWithoutOrder(const vector<vector<T>> &t1,
                         const vector<vector<T>> &t2)
{
    if (t1.size() != t2.size())
        return false;
    bool bRet = true;
    for (int i = 0; i < (int)t2.size() && bRet; ++i) {
        if (find(t1.begin(), t1.end(), t2.at(i)) == t1.end()) {
            bRet = false;
        }
    }
    for (int i = 0; i < (int)t1.size() && bRet; ++i) {
        if (find(t2.begin(), t2.end(), t1.at(i)) == t2.end()) {
            bRet = false;
        }
    }
    return bRet;
}

static int n = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return 0;
}();

#endif // DATA_DEFINE_H_
