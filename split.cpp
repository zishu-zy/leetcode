
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

void split(const std::string &s, const char delim, std::vector<std::string> &sv)
{
    sv.clear();
    std::istringstream iss(s);
    std::string temp;

    while (std::getline(iss, temp, delim)) {
        if (temp.empty())
            continue;
        sv.emplace_back(std::move(temp));
    }
    return;
}

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

std::string readFile(char *file)
{
    std::fstream in(file);
    std::istreambuf_iterator<char> beg(in), end;
    std::string strdata(beg, end);
    in.close();
    return strdata;
}

int main(void)
{
    std::string strdata = readFile((char *)"input.txt");
    std::vector<int> nums;
    split(strdata, ',', nums);
    for (int i = 0; i < (int)nums.size(); ++i) {
        std::cout << nums[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}
