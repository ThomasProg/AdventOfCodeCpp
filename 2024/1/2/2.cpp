#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <algorithm>
#include <cassert>

int main()
{
    std::ifstream filein(WORKSPACE_PATH "input.txt");

    std::vector<int> leftVec;
    std::map<int/*nb*/, int /*count*/> rightVec;

    for (std::string line; std::getline(filein, line); ) 
    {
        int left, right;
        std::istringstream lineStream(line);
        lineStream >> left >> right;

        leftVec.push_back(left);

        auto it = rightVec.find(right);
        if (it == rightVec.end())
        {
            rightVec.emplace_hint(it, right, 1);
        }
        else
        {
            it->second += 1;
        }
    }

    std::sort(leftVec.begin(), leftVec.end());

    using Iterator = std::vector<int>::const_iterator;

    Iterator leftIt = leftVec.begin();

    int similarityScore = 0;

    for (Iterator leftIt = leftVec.begin(); leftIt != leftVec.end(); ++leftIt)
    {
        auto it = rightVec.find(*leftIt);
        if (it != rightVec.end())
        {
            int score = *leftIt * rightVec[*leftIt];
            similarityScore += score;
        }

    }

    std::cout << similarityScore << std::endl;

}