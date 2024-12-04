#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cassert>

bool isReportSafe(const std::vector<int>& report)
{
    if (report.empty())
    {
        return false;
    }

    int sign = 0;
    for (int i = 1; i < report.size(); i++)
    {
        int diff = report[i] - report[i-1];
        int absDiff = std::abs(diff);

        if (absDiff < 1 || absDiff > 3)
        {
            return false;
        }
        
        int newSign = diff / absDiff;
        if (newSign != sign && sign != 0)
        {
            return false;
        }

        sign = newSign;
    }

    return true;
}

bool isReportSafeWithRemoving1Level(const std::vector<int>& report)
{
    for (size_t i = 0; i < report.size(); i++)
    {
        std::vector<int> subReport = report;
        subReport.erase(subReport.begin() + i);

        if (isReportSafe(subReport))
        {
            return true;
        }
    }
    return false;
}

int main()
{
    std::ifstream filein(WORKSPACE_PATH "input.txt");

    int nbValidReports = 0;
    for (std::string line; std::getline(filein, line); ) 
    {
        std::vector<int> list;

        std::string nStr;
        std::istringstream lineStream(line);
        while(std::getline(lineStream, nStr, ' ')) 
        {
            int n = std::stoi(nStr);
            list.emplace_back(n);
        }

        if (isReportSafeWithRemoving1Level(list))
        {
            nbValidReports += 1;
            std::cout << line << " / safe " << std::endl; 
        }
        else 
        {
            std::cout << line << " / unsafe " << std::endl; 
        }
    }

    std::cout << nbValidReports << std::endl;

}