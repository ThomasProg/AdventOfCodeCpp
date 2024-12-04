#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cassert>

int main()
{
    std::ifstream filein(WORKSPACE_PATH "input.txt");

    std::vector<int> leftVec;
    std::vector<int> rightVec;

    for (std::string line; std::getline(filein, line); ) 
    {
        int left, right;
        std::istringstream lineStream(line);
        lineStream >> left >> right;

        leftVec.push_back(left);
        rightVec.push_back(right);
    }

    assert(leftVec.size() == rightVec.size());

    std::sort(leftVec.begin(), leftVec.end());
    std::sort(rightVec.begin(), rightVec.end());

    using Iterator = std::vector<int>::const_iterator;

    Iterator leftIt = leftVec.begin();
    Iterator rightIt = rightVec.begin();

    int distSum = 0;
    while (leftIt != leftVec.end() && rightIt != rightVec.end())
    {
        distSum += std::abs(*leftIt - *rightIt);

        leftIt++;
        rightIt++;
    }

    std::cout << distSum << std::endl;

}