#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cassert>

bool isReportSafe(const std::string& line)
{
    std::string nStr; 
    std::istringstream lineStream(line);

    std::getline(lineStream, nStr, ' ');
    int n = std::stoi(nStr);
    int last = n; 

    int sign = 0;

    while(std::getline(lineStream, nStr, ' ')) 
    {
        int n = std::stoi(nStr);
        
        int diff = n - last;
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
        last = n;
    }

    return true;
}

int main()
{
    std::ifstream filein(WORKSPACE_PATH "input.txt");

    int nbValidReports = 0;
    for (std::string line; std::getline(filein, line); ) 
    {
        if (isReportSafe(line))
        {
            nbValidReports++;
        }
    }

    std::cout << nbValidReports << std::endl;

}