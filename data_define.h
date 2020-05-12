#ifndef DATA_DEFINE_H_
#define DATA_DEFINE_H_

#include <assert.h>
#include <limits.h>
#include <math.h>
#include <algorithm>
#include <fstream>
#include <iostream>
#include <set>
#include <sstream>
#include <stack>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>

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
void print(const vector<vector<T> > &t)
{
    for (auto it = t.begin(); it != t.end(); ++it) {
        print(*it);
    }
}

static int n = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return 0;
}();

#endif // DATA_DEFINE_H_
